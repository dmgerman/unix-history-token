begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)romvec.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* romvec.h Oct-22-1991 */
end_comment

begin_define
define|#
directive|define
name|RVPtr
value|((struct romvec *) 0x41000000)
end_define

begin_define
define|#
directive|define
name|ROM_memsize
value|(*((int *) *RVPtr->vec03))
end_define

begin_define
define|#
directive|define
name|ROM_getchar
value|(*RVPtr->vec06)
end_define

begin_define
define|#
directive|define
name|ROM_putchar
value|(*RVPtr->vec07)
end_define

begin_define
define|#
directive|define
name|ROM_abort
value|(*RVPtr->vec25)
end_define

begin_define
define|#
directive|define
name|ROM_plane
value|(*((int *) *RVPtr->vec46))
end_define

begin_struct
struct|struct
name|romvec
block|{
name|int
function_decl|(
modifier|*
name|vec00
function_decl|)
parameter_list|()
function_decl|;
comment|/* 00 [00] - Cold Boot Entry */
name|int
function_decl|(
modifier|*
name|vec01
function_decl|)
parameter_list|()
function_decl|;
comment|/* 01 [04] */
name|int
function_decl|(
modifier|*
name|vec02
function_decl|)
parameter_list|()
function_decl|;
comment|/* 02 [08] */
name|int
function_decl|(
modifier|*
name|vec03
function_decl|)
parameter_list|()
function_decl|;
comment|/* 03 [0C] - memsize : Memory Size */
name|int
function_decl|(
modifier|*
name|vec04
function_decl|)
parameter_list|()
function_decl|;
comment|/* 04 [10] */
name|int
function_decl|(
modifier|*
name|vec05
function_decl|)
parameter_list|()
function_decl|;
comment|/* 05 [14] */
name|int
function_decl|(
modifier|*
name|vec06
function_decl|)
parameter_list|()
function_decl|;
comment|/* 06 [18] - getchar : get 1 charactor from console	*/
name|int
function_decl|(
modifier|*
name|vec07
function_decl|)
parameter_list|()
function_decl|;
comment|/* 07 [1C] - putchar : put 1 charactor to console		*/
name|int
function_decl|(
modifier|*
name|vec08
function_decl|)
parameter_list|()
function_decl|;
comment|/* 08 [20] */
name|int
function_decl|(
modifier|*
name|vec09
function_decl|)
parameter_list|()
function_decl|;
comment|/* 09 [24] */
name|int
function_decl|(
modifier|*
name|vec10
function_decl|)
parameter_list|()
function_decl|;
comment|/* 10 [28] */
name|int
function_decl|(
modifier|*
name|vec11
function_decl|)
parameter_list|()
function_decl|;
comment|/* 11 [2C] */
name|int
function_decl|(
modifier|*
name|vec12
function_decl|)
parameter_list|()
function_decl|;
comment|/* 12 [30] */
name|int
function_decl|(
modifier|*
name|vec13
function_decl|)
parameter_list|()
function_decl|;
comment|/* 13 [34] */
name|int
function_decl|(
modifier|*
name|vec14
function_decl|)
parameter_list|()
function_decl|;
comment|/* 14 [38] */
name|int
function_decl|(
modifier|*
name|vec15
function_decl|)
parameter_list|()
function_decl|;
comment|/* 15 [3C] */
name|int
function_decl|(
modifier|*
name|vec16
function_decl|)
parameter_list|()
function_decl|;
comment|/* 16 [40] */
name|int
function_decl|(
modifier|*
name|vec17
function_decl|)
parameter_list|()
function_decl|;
comment|/* 17 [44] */
name|int
function_decl|(
modifier|*
name|vec18
function_decl|)
parameter_list|()
function_decl|;
comment|/* 18 [48] */
name|int
function_decl|(
modifier|*
name|vec19
function_decl|)
parameter_list|()
function_decl|;
comment|/* 19 [4C] */
name|int
function_decl|(
modifier|*
name|vec20
function_decl|)
parameter_list|()
function_decl|;
comment|/* 20 [50] */
name|int
function_decl|(
modifier|*
name|vec21
function_decl|)
parameter_list|()
function_decl|;
comment|/* 21 [54] */
name|int
function_decl|(
modifier|*
name|vec22
function_decl|)
parameter_list|()
function_decl|;
comment|/* 22 [58] */
name|int
function_decl|(
modifier|*
name|vec23
function_decl|)
parameter_list|()
function_decl|;
comment|/* 23 [5C] */
name|int
function_decl|(
modifier|*
name|vec24
function_decl|)
parameter_list|()
function_decl|;
comment|/* 24 [60] */
name|int
function_decl|(
modifier|*
name|vec25
function_decl|)
parameter_list|()
function_decl|;
comment|/* 25 [64] - abort : back to ROM Monitor */
name|int
function_decl|(
modifier|*
name|vec26
function_decl|)
parameter_list|()
function_decl|;
comment|/* 26 [68] */
name|int
function_decl|(
modifier|*
name|vec27
function_decl|)
parameter_list|()
function_decl|;
comment|/* 27 [6C] */
name|int
function_decl|(
modifier|*
name|vec28
function_decl|)
parameter_list|()
function_decl|;
comment|/* 28 [70] */
name|int
function_decl|(
modifier|*
name|vec29
function_decl|)
parameter_list|()
function_decl|;
comment|/* 29 [74] */
name|int
function_decl|(
modifier|*
name|vec30
function_decl|)
parameter_list|()
function_decl|;
comment|/* 30 [78] */
name|int
function_decl|(
modifier|*
name|vec31
function_decl|)
parameter_list|()
function_decl|;
comment|/* 31 [7C] */
name|int
function_decl|(
modifier|*
name|vec32
function_decl|)
parameter_list|()
function_decl|;
comment|/* 32 [80] */
name|int
function_decl|(
modifier|*
name|vec33
function_decl|)
parameter_list|()
function_decl|;
comment|/* 33 [84] */
name|int
function_decl|(
modifier|*
name|vec34
function_decl|)
parameter_list|()
function_decl|;
comment|/* 34 [88] */
name|int
function_decl|(
modifier|*
name|vec35
function_decl|)
parameter_list|()
function_decl|;
comment|/* 35 [8C] */
name|int
function_decl|(
modifier|*
name|vec36
function_decl|)
parameter_list|()
function_decl|;
comment|/* 36 [90] */
name|int
function_decl|(
modifier|*
name|vec37
function_decl|)
parameter_list|()
function_decl|;
comment|/* 37 [94] */
name|int
function_decl|(
modifier|*
name|vec38
function_decl|)
parameter_list|()
function_decl|;
comment|/* 38 [98] */
name|int
function_decl|(
modifier|*
name|vec39
function_decl|)
parameter_list|()
function_decl|;
comment|/* 39 [9C] */
name|int
function_decl|(
modifier|*
name|vec40
function_decl|)
parameter_list|()
function_decl|;
comment|/* 40 [A0] */
name|int
function_decl|(
modifier|*
name|vec41
function_decl|)
parameter_list|()
function_decl|;
comment|/* 41 [A4] */
name|int
function_decl|(
modifier|*
name|vec42
function_decl|)
parameter_list|()
function_decl|;
comment|/* 42 [A8] */
name|int
function_decl|(
modifier|*
name|vec43
function_decl|)
parameter_list|()
function_decl|;
comment|/* 43 [AC] */
name|int
function_decl|(
modifier|*
name|vec44
function_decl|)
parameter_list|()
function_decl|;
comment|/* 44 [B0] */
name|int
function_decl|(
modifier|*
name|vec45
function_decl|)
parameter_list|()
function_decl|;
comment|/* 45 [B4] */
name|int
function_decl|(
modifier|*
name|vec46
function_decl|)
parameter_list|()
function_decl|;
comment|/* 46 [B8] -- number of plane */
name|int
function_decl|(
modifier|*
name|vec47
function_decl|)
parameter_list|()
function_decl|;
comment|/* 47 [BC] */
name|int
function_decl|(
modifier|*
name|vec48
function_decl|)
parameter_list|()
function_decl|;
comment|/* 48 [C0] */
name|int
function_decl|(
modifier|*
name|vec49
function_decl|)
parameter_list|()
function_decl|;
comment|/* 49 [C4] */
name|int
function_decl|(
modifier|*
name|vec50
function_decl|)
parameter_list|()
function_decl|;
comment|/* 50 [C8] */
name|int
function_decl|(
modifier|*
name|vec51
function_decl|)
parameter_list|()
function_decl|;
comment|/* 51 [CC] */
name|int
function_decl|(
modifier|*
name|vec52
function_decl|)
parameter_list|()
function_decl|;
comment|/* 52 [D0] */
name|int
function_decl|(
modifier|*
name|vec53
function_decl|)
parameter_list|()
function_decl|;
comment|/* 53 [D4] */
name|int
function_decl|(
modifier|*
name|vec54
function_decl|)
parameter_list|()
function_decl|;
comment|/* 54 [D8] */
name|int
function_decl|(
modifier|*
name|vec55
function_decl|)
parameter_list|()
function_decl|;
comment|/* 55 [DC] */
name|int
function_decl|(
modifier|*
name|vec56
function_decl|)
parameter_list|()
function_decl|;
comment|/* 56 [E0] */
name|int
function_decl|(
modifier|*
name|vec57
function_decl|)
parameter_list|()
function_decl|;
comment|/* 57 [E4] */
name|int
function_decl|(
modifier|*
name|vec58
function_decl|)
parameter_list|()
function_decl|;
comment|/* 58 [E8] */
name|int
function_decl|(
modifier|*
name|vec59
function_decl|)
parameter_list|()
function_decl|;
comment|/* 59 [EC] */
name|int
function_decl|(
modifier|*
name|vec60
function_decl|)
parameter_list|()
function_decl|;
comment|/* 60 [F0] */
name|int
function_decl|(
modifier|*
name|vec61
function_decl|)
parameter_list|()
function_decl|;
comment|/* 61 [F4] */
name|int
function_decl|(
modifier|*
name|vec62
function_decl|)
parameter_list|()
function_decl|;
comment|/* 62 [F8] */
name|int
function_decl|(
modifier|*
name|vec63
function_decl|)
parameter_list|()
function_decl|;
comment|/* 63 [FC] */
block|}
struct|;
end_struct

end_unit

