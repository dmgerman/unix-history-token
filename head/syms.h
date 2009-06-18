begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*	Copyright (c) 1988 AT&T	*/
end_comment

begin_comment
comment|/*	  All Rights Reserved  	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYMS_H
end_ifndef

begin_define
define|#
directive|define
name|_SYMS_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_comment
comment|/* SVr4.0 2.8	*/
end_comment

begin_comment
comment|/*		Storage Classes are defined in storclass.h  */
end_comment

begin_include
include|#
directive|include
file|<storclass.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/*		Number of characters in a symbol name */
define|#
directive|define
name|SYMNMLEN
value|8
comment|/*		Number of characters in a file name */
define|#
directive|define
name|FILNMLEN
value|14
comment|/*		Number of array dimensions in auxiliary entry */
define|#
directive|define
name|DIMNUM
value|4
struct|struct
name|syment
block|{
union|union
block|{
name|char
name|_n_name
index|[
name|SYMNMLEN
index|]
decl_stmt|;
comment|/* old COFF version */
struct|struct
block|{
name|long
name|_n_zeroes
decl_stmt|;
comment|/* new == 0 */
name|long
name|_n_offset
decl_stmt|;
comment|/* offset into string table */
block|}
name|_n_n
struct|;
name|char
modifier|*
name|_n_nptr
index|[
literal|2
index|]
decl_stmt|;
comment|/* allows for overlaying */
block|}
name|_n
union|;
name|unsigned
name|long
name|n_value
decl_stmt|;
comment|/* value of symbol */
name|short
name|n_scnum
decl_stmt|;
comment|/* section number */
name|unsigned
name|short
name|n_type
decl_stmt|;
comment|/* type and derived type */
name|char
name|n_sclass
decl_stmt|;
comment|/* storage class */
name|char
name|n_numaux
decl_stmt|;
comment|/* number of aux. entries */
block|}
struct|;
define|#
directive|define
name|n_name
value|_n._n_name
define|#
directive|define
name|n_nptr
value|_n._n_nptr[1]
define|#
directive|define
name|n_zeroes
value|_n._n_n._n_zeroes
define|#
directive|define
name|n_offset
value|_n._n_n._n_offset
comment|/*  * Relocatable symbols have a section number of the  * section in which they are defined.  Otherwise, section  * numbers have the following meanings:  */
comment|/* undefined symbol */
define|#
directive|define
name|N_UNDEF
value|0
comment|/* value of symbol is absolute */
define|#
directive|define
name|N_ABS
value|-1
comment|/* special debugging symbol -- value of symbol is meaningless */
define|#
directive|define
name|N_DEBUG
value|-2
comment|/* indicates symbol needs transfer vector (preload) */
define|#
directive|define
name|N_TV
value|(unsigned short)-3
comment|/* indicates symbol needs transfer vector (postload) */
define|#
directive|define
name|P_TV
value|(unsigned short)-4
comment|/*  * The fundamental type of a symbol packed into the low  * 4 bits of the word.  */
define|#
directive|define
name|_EF
value|".ef"
define|#
directive|define
name|T_NULL
value|0
define|#
directive|define
name|T_ARG
value|1
comment|/* function argument (only used by compiler) */
define|#
directive|define
name|T_CHAR
value|2
comment|/* character */
define|#
directive|define
name|T_SHORT
value|3
comment|/* short integer */
define|#
directive|define
name|T_INT
value|4
comment|/* integer */
define|#
directive|define
name|T_LONG
value|5
comment|/* long integer */
define|#
directive|define
name|T_FLOAT
value|6
comment|/* floating point */
define|#
directive|define
name|T_DOUBLE
value|7
comment|/* double word */
define|#
directive|define
name|T_STRUCT
value|8
comment|/* structure	*/
define|#
directive|define
name|T_UNION
value|9
comment|/* union	*/
define|#
directive|define
name|T_ENUM
value|10
comment|/* enumeration	*/
define|#
directive|define
name|T_MOE
value|11
comment|/* member of enumeration */
define|#
directive|define
name|T_UCHAR
value|12
comment|/* unsigned character */
define|#
directive|define
name|T_USHORT
value|13
comment|/* unsigned short */
define|#
directive|define
name|T_UINT
value|14
comment|/* unsigned integer */
define|#
directive|define
name|T_ULONG
value|15
comment|/* unsigned long */
comment|/*  * derived types are:  */
define|#
directive|define
name|DT_NON
value|0
comment|/* no derived type */
define|#
directive|define
name|DT_PTR
value|1
comment|/* pointer */
define|#
directive|define
name|DT_FCN
value|2
comment|/* function */
define|#
directive|define
name|DT_ARY
value|3
comment|/* array */
comment|/*  *   type packing constants  */
define|#
directive|define
name|N_BTMASK
value|017
define|#
directive|define
name|N_TMASK
value|060
define|#
directive|define
name|N_TMASK1
value|0300
define|#
directive|define
name|N_TMASK2
value|0360
define|#
directive|define
name|N_BTSHFT
value|4
define|#
directive|define
name|N_TSHIFT
value|2
comment|/*  *   MACROS  */
comment|/*   Basic Type of  x   */
define|#
directive|define
name|BTYPE
parameter_list|(
name|x
parameter_list|)
value|((x)& N_BTMASK)
comment|/*   Is  x  a  pointer ?   */
define|#
directive|define
name|ISPTR
parameter_list|(
name|x
parameter_list|)
value|(((x)& N_TMASK) == (DT_PTR<< N_BTSHFT))
comment|/*   Is  x  a  function ?  */
define|#
directive|define
name|ISFCN
parameter_list|(
name|x
parameter_list|)
value|(((x)& N_TMASK) == (DT_FCN<< N_BTSHFT))
comment|/*   Is  x  an  array ?   */
define|#
directive|define
name|ISARY
parameter_list|(
name|x
parameter_list|)
value|(((x)& N_TMASK) == (DT_ARY<< N_BTSHFT))
comment|/* Is x a structure, union, or enumeration TAG? */
define|#
directive|define
name|ISTAG
parameter_list|(
name|x
parameter_list|)
value|((x) == C_STRTAG || (x) == C_UNTAG || (x) == C_ENTAG)
define|#
directive|define
name|INCREF
parameter_list|(
name|x
parameter_list|)
value|((((x)&~N_BTMASK)<<N_TSHIFT)|(DT_PTR<<N_BTSHFT)|(x&N_BTMASK))
define|#
directive|define
name|DECREF
parameter_list|(
name|x
parameter_list|)
value|((((x)>>N_TSHIFT)&~N_BTMASK)|((x)&N_BTMASK))
comment|/*  *	AUXILIARY ENTRY FORMAT  */
union|union
name|auxent
block|{
struct|struct
block|{
name|long
name|x_tagndx
decl_stmt|;
comment|/* str, un, or enum tag indx */
union|union
block|{
struct|struct
block|{
name|unsigned
name|short
name|x_lnno
decl_stmt|;
comment|/* declaration line */
comment|/* number */
name|unsigned
name|short
name|x_size
decl_stmt|;
comment|/* str, union, array */
comment|/* size */
block|}
name|x_lnsz
struct|;
name|long
name|x_fsize
decl_stmt|;
comment|/* size of function */
block|}
name|x_misc
union|;
union|union
block|{
struct|struct
comment|/* if ISFCN, tag, or .bb */
block|{
name|long
name|x_lnnoptr
decl_stmt|;
comment|/* ptr to fcn line # */
name|long
name|x_endndx
decl_stmt|;
comment|/* entry ndx past */
comment|/* block end */
block|}
name|x_fcn
struct|;
struct|struct
comment|/* if ISARY, up to 4 dimen. */
block|{
name|unsigned
name|short
name|x_dimen
index|[
name|DIMNUM
index|]
decl_stmt|;
block|}
name|x_ary
struct|;
block|}
name|x_fcnary
union|;
name|unsigned
name|short
name|x_tvndx
decl_stmt|;
comment|/* tv index */
block|}
name|x_sym
struct|;
struct|struct
block|{
name|char
name|x_fname
index|[
name|FILNMLEN
index|]
decl_stmt|;
block|}
name|x_file
struct|;
struct|struct
block|{
name|long
name|x_scnlen
decl_stmt|;
comment|/* section length */
name|unsigned
name|short
name|x_nreloc
decl_stmt|;
comment|/* number of reloc entries */
name|unsigned
name|short
name|x_nlinno
decl_stmt|;
comment|/* number of line numbers */
block|}
name|x_scn
struct|;
struct|struct
block|{
name|long
name|x_tvfill
decl_stmt|;
comment|/* tv fill value */
name|unsigned
name|short
name|x_tvlen
decl_stmt|;
comment|/* length of .tv */
name|unsigned
name|short
name|x_tvran
index|[
literal|2
index|]
decl_stmt|;
comment|/* tv range */
block|}
name|x_tv
struct|;
comment|/* info about .tv section (in auxent of symbol .tv)) */
block|}
union|;
define|#
directive|define
name|SYMENT
value|struct syment
define|#
directive|define
name|SYMESZ
value|18
comment|/* sizeof(SYMENT) */
define|#
directive|define
name|AUXENT
value|union auxent
define|#
directive|define
name|AUXESZ
value|18
comment|/* sizeof(AUXENT) */
comment|/*	Defines for "special" symbols   */
define|#
directive|define
name|_ETEXT
value|"etext"
define|#
directive|define
name|_EDATA
value|"edata"
define|#
directive|define
name|_END
value|"end"
define|#
directive|define
name|_START
value|"_start"
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYMS_H */
end_comment

end_unit

