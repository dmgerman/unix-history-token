begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations of constants for internal format of MIPS ECOFF symbols.    Originally contributed by MIPS Computer Systems and Third Eye Software.    Changes contributed by Cygnus Support are in the public domain.     This file is just aggregated with the files that make up the GNU    release; it is not considered part of GAS, GDB, or other GNU    programs.  */
end_comment

begin_comment
comment|/*  * |-----------------------------------------------------------|  * | Copyright (c) 1992, 1991, 1990 MIPS Computer Systems, Inc.|  * | MIPS Computer Systems, Inc. grants reproduction and use   |  * | rights to all parties, PROVIDED that this comment is      |  * | maintained in the copy.                                   |  * |-----------------------------------------------------------|  */
end_comment

begin_comment
comment|/* (C) Copyright 1984 by Third Eye Software, Inc.  *  * Third Eye Software, Inc. grants reproduction and use rights to  * all parties, PROVIDED that this comment is maintained in the copy.  *  * Third Eye makes no claims about the applicability of this  * symbol table to a particular use.  */
end_comment

begin_comment
comment|/* glevels for field in FDR */
end_comment

begin_define
define|#
directive|define
name|GLEVEL_0
value|2
end_define

begin_define
define|#
directive|define
name|GLEVEL_1
value|1
end_define

begin_define
define|#
directive|define
name|GLEVEL_2
value|0
end_define

begin_comment
comment|/* for upward compat reasons. */
end_comment

begin_define
define|#
directive|define
name|GLEVEL_3
value|3
end_define

begin_comment
comment|/* magic number fo symheader */
end_comment

begin_define
define|#
directive|define
name|magicSym
value|0x7009
end_define

begin_comment
comment|/* The Alpha uses this value instead, for some reason.  */
end_comment

begin_define
define|#
directive|define
name|magicSym2
value|0x1992
end_define

begin_comment
comment|/* Language codes */
end_comment

begin_define
define|#
directive|define
name|langC
value|0
end_define

begin_define
define|#
directive|define
name|langPascal
value|1
end_define

begin_define
define|#
directive|define
name|langFortran
value|2
end_define

begin_define
define|#
directive|define
name|langAssembler
value|3
end_define

begin_comment
comment|/* one Assembley inst might map to many mach */
end_comment

begin_define
define|#
directive|define
name|langMachine
value|4
end_define

begin_define
define|#
directive|define
name|langNil
value|5
end_define

begin_define
define|#
directive|define
name|langAda
value|6
end_define

begin_define
define|#
directive|define
name|langPl1
value|7
end_define

begin_define
define|#
directive|define
name|langCobol
value|8
end_define

begin_define
define|#
directive|define
name|langStdc
value|9
end_define

begin_comment
comment|/* FIXME: Collides with SGI langCplusplus */
end_comment

begin_define
define|#
directive|define
name|langCplusplus
value|9
end_define

begin_comment
comment|/* FIXME: Collides with langStdc */
end_comment

begin_define
define|#
directive|define
name|langCplusplusV2
value|10
end_define

begin_comment
comment|/* SGI addition */
end_comment

begin_define
define|#
directive|define
name|langMax
value|11
end_define

begin_comment
comment|/* maximun allowed 32 -- 5 bits */
end_comment

begin_comment
comment|/* The following are value definitions for the fields in the SYMR */
end_comment

begin_comment
comment|/*  * Storage Classes  */
end_comment

begin_define
define|#
directive|define
name|scNil
value|0
end_define

begin_define
define|#
directive|define
name|scText
value|1
end_define

begin_comment
comment|/* text symbol */
end_comment

begin_define
define|#
directive|define
name|scData
value|2
end_define

begin_comment
comment|/* initialized data symbol */
end_comment

begin_define
define|#
directive|define
name|scBss
value|3
end_define

begin_comment
comment|/* un-initialized data symbol */
end_comment

begin_define
define|#
directive|define
name|scRegister
value|4
end_define

begin_comment
comment|/* value of symbol is register number */
end_comment

begin_define
define|#
directive|define
name|scAbs
value|5
end_define

begin_comment
comment|/* value of symbol is absolute */
end_comment

begin_define
define|#
directive|define
name|scUndefined
value|6
end_define

begin_comment
comment|/* who knows? */
end_comment

begin_define
define|#
directive|define
name|scCdbLocal
value|7
end_define

begin_comment
comment|/* variable's value is IN se->va.?? */
end_comment

begin_define
define|#
directive|define
name|scBits
value|8
end_define

begin_comment
comment|/* this is a bit field */
end_comment

begin_define
define|#
directive|define
name|scCdbSystem
value|9
end_define

begin_comment
comment|/* variable's value is IN CDB's address space */
end_comment

begin_define
define|#
directive|define
name|scDbx
value|9
end_define

begin_comment
comment|/* overlap dbx internal use */
end_comment

begin_define
define|#
directive|define
name|scRegImage
value|10
end_define

begin_comment
comment|/* register value saved on stack */
end_comment

begin_define
define|#
directive|define
name|scInfo
value|11
end_define

begin_comment
comment|/* symbol contains debugger information */
end_comment

begin_define
define|#
directive|define
name|scUserStruct
value|12
end_define

begin_comment
comment|/* address in struct user for current process */
end_comment

begin_define
define|#
directive|define
name|scSData
value|13
end_define

begin_comment
comment|/* load time only small data */
end_comment

begin_define
define|#
directive|define
name|scSBss
value|14
end_define

begin_comment
comment|/* load time only small common */
end_comment

begin_define
define|#
directive|define
name|scRData
value|15
end_define

begin_comment
comment|/* load time only read only data */
end_comment

begin_define
define|#
directive|define
name|scVar
value|16
end_define

begin_comment
comment|/* Var parameter (fortran,pascal) */
end_comment

begin_define
define|#
directive|define
name|scCommon
value|17
end_define

begin_comment
comment|/* common variable */
end_comment

begin_define
define|#
directive|define
name|scSCommon
value|18
end_define

begin_comment
comment|/* small common */
end_comment

begin_define
define|#
directive|define
name|scVarRegister
value|19
end_define

begin_comment
comment|/* Var parameter in a register */
end_comment

begin_define
define|#
directive|define
name|scVariant
value|20
end_define

begin_comment
comment|/* Variant record */
end_comment

begin_define
define|#
directive|define
name|scSUndefined
value|21
end_define

begin_comment
comment|/* small undefined(external) data */
end_comment

begin_define
define|#
directive|define
name|scInit
value|22
end_define

begin_comment
comment|/* .init section symbol */
end_comment

begin_define
define|#
directive|define
name|scBasedVar
value|23
end_define

begin_comment
comment|/* Fortran or PL/1 ptr based var */
end_comment

begin_define
define|#
directive|define
name|scXData
value|24
end_define

begin_comment
comment|/* exception handling data */
end_comment

begin_define
define|#
directive|define
name|scPData
value|25
end_define

begin_comment
comment|/* Procedure section */
end_comment

begin_define
define|#
directive|define
name|scFini
value|26
end_define

begin_comment
comment|/* .fini section */
end_comment

begin_define
define|#
directive|define
name|scRConst
value|27
end_define

begin_comment
comment|/* .rconst section */
end_comment

begin_define
define|#
directive|define
name|scMax
value|32
end_define

begin_comment
comment|/*  *   Symbol Types  */
end_comment

begin_define
define|#
directive|define
name|stNil
value|0
end_define

begin_comment
comment|/* Nuthin' special */
end_comment

begin_define
define|#
directive|define
name|stGlobal
value|1
end_define

begin_comment
comment|/* external symbol */
end_comment

begin_define
define|#
directive|define
name|stStatic
value|2
end_define

begin_comment
comment|/* static */
end_comment

begin_define
define|#
directive|define
name|stParam
value|3
end_define

begin_comment
comment|/* procedure argument */
end_comment

begin_define
define|#
directive|define
name|stLocal
value|4
end_define

begin_comment
comment|/* local variable */
end_comment

begin_define
define|#
directive|define
name|stLabel
value|5
end_define

begin_comment
comment|/* label */
end_comment

begin_define
define|#
directive|define
name|stProc
value|6
end_define

begin_comment
comment|/*     "      "	 Procedure */
end_comment

begin_define
define|#
directive|define
name|stBlock
value|7
end_define

begin_comment
comment|/* beginnning of block */
end_comment

begin_define
define|#
directive|define
name|stEnd
value|8
end_define

begin_comment
comment|/* end (of anything) */
end_comment

begin_define
define|#
directive|define
name|stMember
value|9
end_define

begin_comment
comment|/* member (of anything	- struct/union/enum */
end_comment

begin_define
define|#
directive|define
name|stTypedef
value|10
end_define

begin_comment
comment|/* type definition */
end_comment

begin_define
define|#
directive|define
name|stFile
value|11
end_define

begin_comment
comment|/* file name */
end_comment

begin_define
define|#
directive|define
name|stRegReloc
value|12
end_define

begin_comment
comment|/* register relocation */
end_comment

begin_define
define|#
directive|define
name|stForward
value|13
end_define

begin_comment
comment|/* forwarding address */
end_comment

begin_define
define|#
directive|define
name|stStaticProc
value|14
end_define

begin_comment
comment|/* load time only static procs */
end_comment

begin_define
define|#
directive|define
name|stConstant
value|15
end_define

begin_comment
comment|/* const */
end_comment

begin_define
define|#
directive|define
name|stStaParam
value|16
end_define

begin_comment
comment|/* Fortran static parameters */
end_comment

begin_comment
comment|/* These new symbol types have been recently added to SGI machines. */
end_comment

begin_define
define|#
directive|define
name|stStruct
value|26
end_define

begin_comment
comment|/* Beginning of block defining a struct type */
end_comment

begin_define
define|#
directive|define
name|stUnion
value|27
end_define

begin_comment
comment|/* Beginning of block defining a union type */
end_comment

begin_define
define|#
directive|define
name|stEnum
value|28
end_define

begin_comment
comment|/* Beginning of block defining an enum type */
end_comment

begin_define
define|#
directive|define
name|stIndirect
value|34
end_define

begin_comment
comment|/* Indirect type specification */
end_comment

begin_comment
comment|/* Pseudo-symbols - internal to debugger */
end_comment

begin_define
define|#
directive|define
name|stStr
value|60
end_define

begin_comment
comment|/* string */
end_comment

begin_define
define|#
directive|define
name|stNumber
value|61
end_define

begin_comment
comment|/* pure number (ie. 4 NOR 2+2) */
end_comment

begin_define
define|#
directive|define
name|stExpr
value|62
end_define

begin_comment
comment|/* 2+2 vs. 4 */
end_comment

begin_define
define|#
directive|define
name|stType
value|63
end_define

begin_comment
comment|/* post-coersion SER */
end_comment

begin_define
define|#
directive|define
name|stMax
value|64
end_define

begin_comment
comment|/* definitions for fields in TIR */
end_comment

begin_comment
comment|/* type qualifiers for ti.tq0 -> ti.(itqMax-1) */
end_comment

begin_define
define|#
directive|define
name|tqNil
value|0
end_define

begin_comment
comment|/* bt is what you see */
end_comment

begin_define
define|#
directive|define
name|tqPtr
value|1
end_define

begin_comment
comment|/* pointer */
end_comment

begin_define
define|#
directive|define
name|tqProc
value|2
end_define

begin_comment
comment|/* procedure */
end_comment

begin_define
define|#
directive|define
name|tqArray
value|3
end_define

begin_comment
comment|/* duh */
end_comment

begin_define
define|#
directive|define
name|tqFar
value|4
end_define

begin_comment
comment|/* longer addressing - 8086/8 land */
end_comment

begin_define
define|#
directive|define
name|tqVol
value|5
end_define

begin_comment
comment|/* volatile */
end_comment

begin_define
define|#
directive|define
name|tqConst
value|6
end_define

begin_comment
comment|/* const */
end_comment

begin_define
define|#
directive|define
name|tqMax
value|8
end_define

begin_comment
comment|/* basic types as seen in ti.bt */
end_comment

begin_define
define|#
directive|define
name|btNil
value|0
end_define

begin_comment
comment|/* undefined (also, enum members) */
end_comment

begin_define
define|#
directive|define
name|btAdr
value|1
end_define

begin_comment
comment|/* address - integer same size as pointer */
end_comment

begin_define
define|#
directive|define
name|btChar
value|2
end_define

begin_comment
comment|/* character */
end_comment

begin_define
define|#
directive|define
name|btUChar
value|3
end_define

begin_comment
comment|/* unsigned character */
end_comment

begin_define
define|#
directive|define
name|btShort
value|4
end_define

begin_comment
comment|/* short */
end_comment

begin_define
define|#
directive|define
name|btUShort
value|5
end_define

begin_comment
comment|/* unsigned short */
end_comment

begin_define
define|#
directive|define
name|btInt
value|6
end_define

begin_comment
comment|/* int */
end_comment

begin_define
define|#
directive|define
name|btUInt
value|7
end_define

begin_comment
comment|/* unsigned int */
end_comment

begin_define
define|#
directive|define
name|btLong
value|8
end_define

begin_comment
comment|/* long */
end_comment

begin_define
define|#
directive|define
name|btULong
value|9
end_define

begin_comment
comment|/* unsigned long */
end_comment

begin_define
define|#
directive|define
name|btFloat
value|10
end_define

begin_comment
comment|/* float (real) */
end_comment

begin_define
define|#
directive|define
name|btDouble
value|11
end_define

begin_comment
comment|/* Double (real) */
end_comment

begin_define
define|#
directive|define
name|btStruct
value|12
end_define

begin_comment
comment|/* Structure (Record) */
end_comment

begin_define
define|#
directive|define
name|btUnion
value|13
end_define

begin_comment
comment|/* Union (variant) */
end_comment

begin_define
define|#
directive|define
name|btEnum
value|14
end_define

begin_comment
comment|/* Enumerated */
end_comment

begin_define
define|#
directive|define
name|btTypedef
value|15
end_define

begin_comment
comment|/* defined via a typedef, isymRef points */
end_comment

begin_define
define|#
directive|define
name|btRange
value|16
end_define

begin_comment
comment|/* subrange of int */
end_comment

begin_define
define|#
directive|define
name|btSet
value|17
end_define

begin_comment
comment|/* pascal sets */
end_comment

begin_define
define|#
directive|define
name|btComplex
value|18
end_define

begin_comment
comment|/* fortran complex */
end_comment

begin_define
define|#
directive|define
name|btDComplex
value|19
end_define

begin_comment
comment|/* fortran double complex */
end_comment

begin_define
define|#
directive|define
name|btIndirect
value|20
end_define

begin_comment
comment|/* forward or unnamed typedef */
end_comment

begin_define
define|#
directive|define
name|btFixedDec
value|21
end_define

begin_comment
comment|/* Fixed Decimal */
end_comment

begin_define
define|#
directive|define
name|btFloatDec
value|22
end_define

begin_comment
comment|/* Float Decimal */
end_comment

begin_define
define|#
directive|define
name|btString
value|23
end_define

begin_comment
comment|/* Varying Length Character String */
end_comment

begin_define
define|#
directive|define
name|btBit
value|24
end_define

begin_comment
comment|/* Aligned Bit String */
end_comment

begin_define
define|#
directive|define
name|btPicture
value|25
end_define

begin_comment
comment|/* Picture */
end_comment

begin_define
define|#
directive|define
name|btVoid
value|26
end_define

begin_comment
comment|/* void */
end_comment

begin_define
define|#
directive|define
name|btLongLong
value|27
end_define

begin_comment
comment|/* long long */
end_comment

begin_define
define|#
directive|define
name|btULongLong
value|28
end_define

begin_comment
comment|/* unsigned long long */
end_comment

begin_define
define|#
directive|define
name|btMax
value|64
end_define

begin_if
if|#
directive|if
operator|(
name|_MFG
operator|==
name|_MIPS
operator|)
end_if

begin_comment
comment|/* optimization type codes */
end_comment

begin_define
define|#
directive|define
name|otNil
value|0
end_define

begin_define
define|#
directive|define
name|otReg
value|1
end_define

begin_comment
comment|/* move var to reg */
end_comment

begin_define
define|#
directive|define
name|otBlock
value|2
end_define

begin_comment
comment|/* begin basic block */
end_comment

begin_define
define|#
directive|define
name|otProc
value|3
end_define

begin_comment
comment|/* procedure */
end_comment

begin_define
define|#
directive|define
name|otInline
value|4
end_define

begin_comment
comment|/* inline procedure */
end_comment

begin_define
define|#
directive|define
name|otEnd
value|5
end_define

begin_comment
comment|/* whatever you started */
end_comment

begin_define
define|#
directive|define
name|otMax
value|6
end_define

begin_comment
comment|/* KEEP UP TO DATE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (_MFG == _MIPS) */
end_comment

end_unit

