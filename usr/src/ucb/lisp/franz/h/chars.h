begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*					-[Sat Jan 29 13:52:05 1983 by jkf]-  * 	chars.h				$Locker:  $  * lexical table   *  * $Header: /na/franz/franz/h/chars.h,v 1.1 83/01/29 14:03:08 jkf Exp $  *  * (c) copyright 1982, Regents of the University of California  */
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
name|CNUM
value|0000
end_define

begin_define
define|#
directive|define
name|CSIGN
value|0001
end_define

begin_define
define|#
directive|define
name|CCHAR
value|0002
end_define

begin_define
define|#
directive|define
name|CLPARA
value|0003
end_define

begin_define
define|#
directive|define
name|CRPARA
value|0004
end_define

begin_define
define|#
directive|define
name|CPERD
value|0005
end_define

begin_define
define|#
directive|define
name|CLBRCK
value|0006
end_define

begin_define
define|#
directive|define
name|CRBRCK
value|0007
end_define

begin_define
define|#
directive|define
name|CSQ
value|0011
end_define

begin_define
define|#
directive|define
name|CDQ
value|0012
end_define

begin_define
define|#
directive|define
name|CERR
value|0013
end_define

begin_define
define|#
directive|define
name|CSEP
value|0014
end_define

begin_define
define|#
directive|define
name|CSPL
value|0015
end_define

begin_define
define|#
directive|define
name|CMAC
value|0016
end_define

begin_define
define|#
directive|define
name|CESC
value|0017
end_define

begin_define
define|#
directive|define
name|CSCA
value|0020
end_define

begin_define
define|#
directive|define
name|CSD
value|0021
end_define

begin_define
define|#
directive|define
name|CSMAC
value|0022
end_define

begin_define
define|#
directive|define
name|CSSPL
value|0023
end_define

begin_define
define|#
directive|define
name|CINF
value|0024
end_define

begin_define
define|#
directive|define
name|CSINF
value|0025
end_define

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
name|VLPARA
value|(CLPARA|QALWAYS|SEPMASK)
end_define

begin_define
define|#
directive|define
name|VRPARA
value|(CRPARA|QALWAYS|SEPMASK)
end_define

begin_define
define|#
directive|define
name|VPERD
value|(CPERD|QWNUNIQ)
end_define

begin_define
define|#
directive|define
name|VLBRCK
value|(CLBRCK|QALWAYS|SEPMASK)
end_define

begin_define
define|#
directive|define
name|VRBRCK
value|(CRBRCK|QALWAYS|SEPMASK)
end_define

begin_define
define|#
directive|define
name|VSQ
value|(CSQ|QALWAYS|SEPMASK)
end_define

begin_define
define|#
directive|define
name|VDQ
value|(CDQ|QALWAYS)
end_define

begin_define
define|#
directive|define
name|VERR
value|(CERR|QALWAYS|SEPMASK)
end_define

begin_define
define|#
directive|define
name|VSEP
value|(CSEP|QALWAYS|SEPMASK)
end_define

begin_define
define|#
directive|define
name|VSPL
value|(CSPL|QALWAYS|SEPMASK)
end_define

begin_define
define|#
directive|define
name|VMAC
value|(CMAC|QALWAYS|SEPMASK)
end_define

begin_define
define|#
directive|define
name|VESC
value|(CESC|QALWAYS)
end_define

begin_define
define|#
directive|define
name|VSCA
value|(CSCA|SEPMASK)
end_define

begin_define
define|#
directive|define
name|VSD
value|(CSD|QALWAYS)
end_define

begin_define
define|#
directive|define
name|VSMAC
value|(CSMAC|QWNUNIQ)
end_define

begin_define
define|#
directive|define
name|VSSPL
value|(CSSPL|QWNUNIQ)
end_define

begin_define
define|#
directive|define
name|VINF
value|0024
end_define

begin_define
define|#
directive|define
name|VSINF
value|(CSINF|QWNUNIQ)
end_define

begin_define
define|#
directive|define
name|QUTMASK
value|0300
end_define

begin_define
define|#
directive|define
name|SEPMASK
value|0040
end_define

begin_define
define|#
directive|define
name|QALWAYS
value|0300
end_define

begin_define
define|#
directive|define
name|QWNUNIQ
value|0100
end_define

begin_define
define|#
directive|define
name|QWNFRST
value|0200
end_define

begin_define
define|#
directive|define
name|synclass
parameter_list|(
name|p
parameter_list|)
value|(p& 037)
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

begin_define
define|#
directive|define
name|TINF
value|10
end_define

end_unit

