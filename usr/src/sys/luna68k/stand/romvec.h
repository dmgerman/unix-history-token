begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)romvec.h	7.1 (Berkeley) %G%  */
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
comment|/* 00 - Cold Boot Entry */
name|int
function_decl|(
modifier|*
name|vec01
function_decl|)
parameter_list|()
function_decl|;
comment|/* 01 */
name|int
function_decl|(
modifier|*
name|vec02
function_decl|)
parameter_list|()
function_decl|;
comment|/* 02 */
name|int
function_decl|(
modifier|*
name|vec03
function_decl|)
parameter_list|()
function_decl|;
comment|/* 03 - memsize : Memory Size */
name|int
function_decl|(
modifier|*
name|vec04
function_decl|)
parameter_list|()
function_decl|;
comment|/* 04 */
name|int
function_decl|(
modifier|*
name|vec05
function_decl|)
parameter_list|()
function_decl|;
comment|/* 05 */
name|int
function_decl|(
modifier|*
name|vec06
function_decl|)
parameter_list|()
function_decl|;
comment|/* 06 - getchar : get 1 charactor from console	*/
name|int
function_decl|(
modifier|*
name|vec07
function_decl|)
parameter_list|()
function_decl|;
comment|/* 07 - putchar : put 1 charactor to console		*/
name|int
function_decl|(
modifier|*
name|vec08
function_decl|)
parameter_list|()
function_decl|;
comment|/* 08 */
name|int
function_decl|(
modifier|*
name|vec09
function_decl|)
parameter_list|()
function_decl|;
comment|/* 09 */
name|int
function_decl|(
modifier|*
name|vec10
function_decl|)
parameter_list|()
function_decl|;
comment|/* 10 */
name|int
function_decl|(
modifier|*
name|vec11
function_decl|)
parameter_list|()
function_decl|;
comment|/* 11 */
name|int
function_decl|(
modifier|*
name|vec12
function_decl|)
parameter_list|()
function_decl|;
comment|/* 12 */
name|int
function_decl|(
modifier|*
name|vec13
function_decl|)
parameter_list|()
function_decl|;
comment|/* 13 */
name|int
function_decl|(
modifier|*
name|vec14
function_decl|)
parameter_list|()
function_decl|;
comment|/* 14 */
name|int
function_decl|(
modifier|*
name|vec15
function_decl|)
parameter_list|()
function_decl|;
comment|/* 15 */
name|int
function_decl|(
modifier|*
name|vec16
function_decl|)
parameter_list|()
function_decl|;
comment|/* 16 */
name|int
function_decl|(
modifier|*
name|vec17
function_decl|)
parameter_list|()
function_decl|;
comment|/* 17 */
name|int
function_decl|(
modifier|*
name|vec18
function_decl|)
parameter_list|()
function_decl|;
comment|/* 18 */
name|int
function_decl|(
modifier|*
name|vec19
function_decl|)
parameter_list|()
function_decl|;
comment|/* 19 */
name|int
function_decl|(
modifier|*
name|vec20
function_decl|)
parameter_list|()
function_decl|;
comment|/* 20 */
name|int
function_decl|(
modifier|*
name|vec21
function_decl|)
parameter_list|()
function_decl|;
comment|/* 21 */
name|int
function_decl|(
modifier|*
name|vec22
function_decl|)
parameter_list|()
function_decl|;
comment|/* 22 */
name|int
function_decl|(
modifier|*
name|vec23
function_decl|)
parameter_list|()
function_decl|;
comment|/* 23 */
name|int
function_decl|(
modifier|*
name|vec24
function_decl|)
parameter_list|()
function_decl|;
comment|/* 24 */
name|int
function_decl|(
modifier|*
name|vec25
function_decl|)
parameter_list|()
function_decl|;
comment|/* 25 - abort : back to ROM Monitor */
name|int
function_decl|(
modifier|*
name|vec26
function_decl|)
parameter_list|()
function_decl|;
comment|/* 26 */
name|int
function_decl|(
modifier|*
name|vec27
function_decl|)
parameter_list|()
function_decl|;
comment|/* 27 */
name|int
function_decl|(
modifier|*
name|vec28
function_decl|)
parameter_list|()
function_decl|;
comment|/* 28 */
name|int
function_decl|(
modifier|*
name|vec29
function_decl|)
parameter_list|()
function_decl|;
comment|/* 29 */
name|int
function_decl|(
modifier|*
name|vec30
function_decl|)
parameter_list|()
function_decl|;
comment|/* 30 */
name|int
function_decl|(
modifier|*
name|vec31
function_decl|)
parameter_list|()
function_decl|;
comment|/* 31 */
name|int
function_decl|(
modifier|*
name|vec32
function_decl|)
parameter_list|()
function_decl|;
comment|/* 32 */
name|int
function_decl|(
modifier|*
name|vec33
function_decl|)
parameter_list|()
function_decl|;
comment|/* 33 */
name|int
function_decl|(
modifier|*
name|vec34
function_decl|)
parameter_list|()
function_decl|;
comment|/* 34 */
name|int
function_decl|(
modifier|*
name|vec35
function_decl|)
parameter_list|()
function_decl|;
comment|/* 35 */
name|int
function_decl|(
modifier|*
name|vec36
function_decl|)
parameter_list|()
function_decl|;
comment|/* 36 */
name|int
function_decl|(
modifier|*
name|vec37
function_decl|)
parameter_list|()
function_decl|;
comment|/* 37 */
name|int
function_decl|(
modifier|*
name|vec38
function_decl|)
parameter_list|()
function_decl|;
comment|/* 38 */
name|int
function_decl|(
modifier|*
name|vec39
function_decl|)
parameter_list|()
function_decl|;
comment|/* 39 */
name|int
function_decl|(
modifier|*
name|vec40
function_decl|)
parameter_list|()
function_decl|;
comment|/* 40 */
name|int
function_decl|(
modifier|*
name|vec41
function_decl|)
parameter_list|()
function_decl|;
comment|/* 41 */
name|int
function_decl|(
modifier|*
name|vec42
function_decl|)
parameter_list|()
function_decl|;
comment|/* 42 */
name|int
function_decl|(
modifier|*
name|vec43
function_decl|)
parameter_list|()
function_decl|;
comment|/* 43 */
name|int
function_decl|(
modifier|*
name|vec44
function_decl|)
parameter_list|()
function_decl|;
comment|/* 44 */
name|int
function_decl|(
modifier|*
name|vec45
function_decl|)
parameter_list|()
function_decl|;
comment|/* 45 */
name|int
function_decl|(
modifier|*
name|vec46
function_decl|)
parameter_list|()
function_decl|;
comment|/* 46 */
name|int
function_decl|(
modifier|*
name|vec47
function_decl|)
parameter_list|()
function_decl|;
comment|/* 47 */
name|int
function_decl|(
modifier|*
name|vec48
function_decl|)
parameter_list|()
function_decl|;
comment|/* 48 */
name|int
function_decl|(
modifier|*
name|vec49
function_decl|)
parameter_list|()
function_decl|;
comment|/* 49 */
name|int
function_decl|(
modifier|*
name|vec50
function_decl|)
parameter_list|()
function_decl|;
comment|/* 50 */
name|int
function_decl|(
modifier|*
name|vec51
function_decl|)
parameter_list|()
function_decl|;
comment|/* 51 */
name|int
function_decl|(
modifier|*
name|vec52
function_decl|)
parameter_list|()
function_decl|;
comment|/* 52 */
name|int
function_decl|(
modifier|*
name|vec53
function_decl|)
parameter_list|()
function_decl|;
comment|/* 53 */
name|int
function_decl|(
modifier|*
name|vec54
function_decl|)
parameter_list|()
function_decl|;
comment|/* 54 */
name|int
function_decl|(
modifier|*
name|vec55
function_decl|)
parameter_list|()
function_decl|;
comment|/* 55 */
name|int
function_decl|(
modifier|*
name|vec56
function_decl|)
parameter_list|()
function_decl|;
comment|/* 56 */
name|int
function_decl|(
modifier|*
name|vec57
function_decl|)
parameter_list|()
function_decl|;
comment|/* 57 */
name|int
function_decl|(
modifier|*
name|vec58
function_decl|)
parameter_list|()
function_decl|;
comment|/* 58 */
name|int
function_decl|(
modifier|*
name|vec59
function_decl|)
parameter_list|()
function_decl|;
comment|/* 59 */
name|int
function_decl|(
modifier|*
name|vec60
function_decl|)
parameter_list|()
function_decl|;
comment|/* 60 */
name|int
function_decl|(
modifier|*
name|vec61
function_decl|)
parameter_list|()
function_decl|;
comment|/* 61 */
name|int
function_decl|(
modifier|*
name|vec62
function_decl|)
parameter_list|()
function_decl|;
comment|/* 62 */
name|int
function_decl|(
modifier|*
name|vec63
function_decl|)
parameter_list|()
function_decl|;
comment|/* 63 */
name|int
function_decl|(
modifier|*
name|vec64
function_decl|)
parameter_list|()
function_decl|;
comment|/* 64 */
name|int
function_decl|(
modifier|*
name|vec65
function_decl|)
parameter_list|()
function_decl|;
comment|/* 65 */
name|int
function_decl|(
modifier|*
name|vec66
function_decl|)
parameter_list|()
function_decl|;
comment|/* 66 */
name|int
function_decl|(
modifier|*
name|vec67
function_decl|)
parameter_list|()
function_decl|;
comment|/* 67 */
name|int
function_decl|(
modifier|*
name|vec68
function_decl|)
parameter_list|()
function_decl|;
comment|/* 68 */
name|int
function_decl|(
modifier|*
name|vec69
function_decl|)
parameter_list|()
function_decl|;
comment|/* 69 */
block|}
struct|;
end_struct

end_unit

