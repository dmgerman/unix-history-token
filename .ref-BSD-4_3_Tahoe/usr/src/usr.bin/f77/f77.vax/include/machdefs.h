begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * machdefs.h  *  * Machine definitions for f77 compiler, pass 1.  VAX version.  *  * University of Utah CS Dept modification history:  *  * $Header: machdefs.h,v 2.2 85/01/14 03:41:13 donn Exp $  * $Log:	machdefs.h,v $  * Revision 2.2  85/01/14  03:41:13  donn  * Added changes to make the storage used for constants that are passed  * as arguments to functions come out read-only.  *   * Revision 2.1  84/07/19  12:55:11  donn  * Changed comment header to UofU.  *   * Revision 1.3  84/07/02  12:04:42  donn  * I goofed when I added the original changes for SZFLOAT and SZDOUBLE.  * Thanks to Raleigh Romine for pointing this out (sigh).  *   * Revision 1.2  84/02/28  20:46:16  donn  * Added definitions for SZFLOAT and SZDOUBLE, needed by Berkeley changes to  * produce shorter offsets to variables in machine code.  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET
end_ifndef

begin_expr_stmt
name|TARGET
name|NOT
name|DEFINED
operator|!
operator|!
operator|!
endif|#
directive|endif
if|#
directive|if
name|TARGET
operator|!=
name|VAX
name|Target
operator|=
name|TARGET
name|OUT
name|OF
name|RANGE
operator|!
operator|!
endif|#
directive|endif
ifndef|#
directive|ifndef
name|FAMILY
name|FAMILY
name|NOT
name|DEFINED
operator|!
operator|!
operator|!
endif|#
directive|endif
if|#
directive|if
name|FAMILY
operator|!=
name|PCC
operator|&&
name|FAMILY
operator|!=
name|DMR
name|Family
operator|=
name|FAMILY
name|OUT
name|OF
name|RANGE
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SDB
value|1
end_define

begin_define
define|#
directive|define
name|TYLENG
value|TYLONG
end_define

begin_define
define|#
directive|define
name|TYINT
value|TYLONG
end_define

begin_define
define|#
directive|define
name|SZADDR
value|4
end_define

begin_define
define|#
directive|define
name|SZSHORT
value|2
end_define

begin_define
define|#
directive|define
name|SZINT
value|4
end_define

begin_define
define|#
directive|define
name|SZFLOAT
value|4
end_define

begin_define
define|#
directive|define
name|SZDOUBLE
value|8
end_define

begin_define
define|#
directive|define
name|SZLONG
value|4
end_define

begin_define
define|#
directive|define
name|SZLENG
value|SZLONG
end_define

begin_define
define|#
directive|define
name|ALIADDR
value|SZADDR
end_define

begin_define
define|#
directive|define
name|ALISHORT
value|SZSHORT
end_define

begin_define
define|#
directive|define
name|ALILONG
value|4
end_define

begin_define
define|#
directive|define
name|ALIDOUBLE
value|4
end_define

begin_define
define|#
directive|define
name|ALIINT
value|ALILONG
end_define

begin_define
define|#
directive|define
name|ALILENG
value|ALILONG
end_define

begin_define
define|#
directive|define
name|AUTOREG
value|13
end_define

begin_define
define|#
directive|define
name|ARGREG
value|12
end_define

begin_define
define|#
directive|define
name|CARGREG
value|12
end_define

begin_define
define|#
directive|define
name|ARGOFFSET
value|4
end_define

begin_define
define|#
directive|define
name|SAVESPACE
value|40
end_define

begin_define
define|#
directive|define
name|FUDGEOFFSET
value|1
end_define

begin_define
define|#
directive|define
name|BITSPERCHAR
value|8
end_define

begin_define
define|#
directive|define
name|XL
value|16
end_define

begin_define
define|#
directive|define
name|USETEXT
value|".text\t0"
end_define

begin_define
define|#
directive|define
name|USECONST
value|".text\t1"
end_define

begin_define
define|#
directive|define
name|USEBSS
value|".data\t0"
end_define

begin_define
define|#
directive|define
name|USEINIT
value|".data\t1"
end_define

begin_define
define|#
directive|define
name|BLANKCOMMON
value|"_BLNK_"
end_define

begin_define
define|#
directive|define
name|LABELFMT
value|"%s:\n"
end_define

begin_define
define|#
directive|define
name|MAXREGVAR
value|5
end_define

begin_define
define|#
directive|define
name|TYIREG
value|TYLONG
end_define

begin_define
define|#
directive|define
name|MSKIREG
value|(M(TYSHORT)|M(TYLONG))
end_define

begin_define
define|#
directive|define
name|MAXINT
value|2147483647
end_define

begin_define
define|#
directive|define
name|MININT
value|((-2147483647) - 1)
end_define

begin_define
define|#
directive|define
name|MAXBYTE
value|255
end_define

begin_define
define|#
directive|define
name|BYTESIZE
value|8
end_define

begin_define
define|#
directive|define
name|SMALLVAR
parameter_list|(
name|x
parameter_list|)
value|((x)< 512)
end_define

end_unit

