begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This is a minimally edited version of Guile's tags.h. */
end_comment

begin_comment
comment|/* classes: h_files */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TAGSH
end_ifndef

begin_define
define|#
directive|define
name|TAGSH
end_define

begin_comment
comment|/*	Copyright (C) 1995 Free Software Foundation, Inc.  *   * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2, or (at your option)  * any later version.  *   * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *   * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  *  * As a special exception, the Free Software Foundation gives permission  * for additional uses of the text contained in its release of GUILE.  *  * The exception is that, if you link the GUILE library with other files  * to produce an executable, this does not by itself cause the  * resulting executable to be covered by the GNU General Public License.  * Your use of that executable is in no way restricted on account of  * linking the GUILE library code into it.  *  * This exception does not however invalidate any other reasons why  * the executable file might be covered by the GNU General Public License.  *  * This exception applies only to the code released by the  * Free Software Foundation under the name GUILE.  If you copy  * code from other Free Software Foundation releases into a copy of  * GUILE, as the General Public License permits, the exception does  * not apply to the code that you add in this way.  To avoid misleading  * anyone as to the status of such modified files, you must delete  * this exception notice from them.  *  * If you write modifications of your own for GUILE, it is your choice  * whether to permit this exception to apply to your modifications.  * If you do not wish that, delete this exception notice.    */
end_comment

begin_escape
end_escape

begin_comment
comment|/** This file defines the format of SCM values and cons pairs.    ** It is here that tag bits are assigned for various purposes.  **/
end_comment

begin_escape
end_escape

begin_comment
comment|/* Three Bit Tags  *  * 000 -- a non-immediate value.  Points into the pair heap.    *  * 001 -- a gloc (i.e., a resolved global variable in a CAR in a code graph)  *	  or the CAR of an object handle (i.e., the tagged pointer to the  *	  vtable part of a user-defined object).  *  *        If X has this tag, the value at CDAR(X - 1) distinguishes  *	  glocs from object handles.  The distinction only needs  *	  to be made in a few places.  Only a few parts of the code know  *	  about glocs.  In most cases, when a value in the CAR of a pair  *	  has the tag 001, it means that the pair is an object handle.  *  * 010 -- the tag for immediate, exact integers.   *  * 011 -- in the CAR of a pair, this tag indicates that the pair is a closure.  *	  The remaining bits of the CAR are a pointer into the pair heap  * 	  to the code graph for the closure.  *  * 1xy -- an extension tag which means that there is a five or six bit  *	  tag to the left of the low three bits.  See the nice diagrams  *	  in ../doc/code.doc if you want to know what the bits mean.  */
end_comment

begin_escape
end_escape

begin_define
define|#
directive|define
name|scm_tc3_cons
value|0
end_define

begin_define
define|#
directive|define
name|scm_tc3_cons_gloc
value|1
end_define

begin_define
define|#
directive|define
name|scm_tc3_closure
value|3
end_define

begin_define
define|#
directive|define
name|scm_tc7_ssymbol
value|5
end_define

begin_define
define|#
directive|define
name|scm_tc7_msymbol
value|7
end_define

begin_define
define|#
directive|define
name|scm_tc7_string
value|13
end_define

begin_define
define|#
directive|define
name|scm_tc7_bvect
value|15
end_define

begin_define
define|#
directive|define
name|scm_tc7_vector
value|21
end_define

begin_define
define|#
directive|define
name|scm_tc7_lvector
value|23
end_define

begin_define
define|#
directive|define
name|scm_tc7_ivect
value|29
end_define

begin_define
define|#
directive|define
name|scm_tc7_uvect
value|31
end_define

begin_comment
comment|/* spare 37 39 */
end_comment

begin_define
define|#
directive|define
name|scm_tc7_fvect
value|45
end_define

begin_define
define|#
directive|define
name|scm_tc7_dvect
value|47
end_define

begin_define
define|#
directive|define
name|scm_tc7_cvect
value|53
end_define

begin_define
define|#
directive|define
name|scm_tc7_port
value|55
end_define

begin_define
define|#
directive|define
name|scm_tc7_contin
value|61
end_define

begin_define
define|#
directive|define
name|scm_tc7_cclo
value|63
end_define

begin_comment
comment|/* spare 69 71 77 79 */
end_comment

begin_define
define|#
directive|define
name|scm_tc7_subr_0
value|85
end_define

begin_define
define|#
directive|define
name|scm_tc7_subr_1
value|87
end_define

begin_define
define|#
directive|define
name|scm_tc7_cxr
value|93
end_define

begin_define
define|#
directive|define
name|scm_tc7_subr_3
value|95
end_define

begin_define
define|#
directive|define
name|scm_tc7_subr_2
value|101
end_define

begin_define
define|#
directive|define
name|scm_tc7_asubr
value|103
end_define

begin_define
define|#
directive|define
name|scm_tc7_subr_1o
value|109
end_define

begin_define
define|#
directive|define
name|scm_tc7_subr_2o
value|111
end_define

begin_define
define|#
directive|define
name|scm_tc7_lsubr_2
value|117
end_define

begin_define
define|#
directive|define
name|scm_tc7_lsubr
value|119
end_define

begin_define
define|#
directive|define
name|scm_tc7_rpsubr
value|125
end_define

begin_define
define|#
directive|define
name|scm_tc7_smob
value|127
end_define

begin_define
define|#
directive|define
name|scm_tc_free_cell
value|127
end_define

begin_define
define|#
directive|define
name|scm_tc16_flo
value|0x017f
end_define

begin_define
define|#
directive|define
name|scm_tc_flo
value|0x017fL
end_define

begin_define
define|#
directive|define
name|SCM_REAL_PART
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|SCM_IMAG_PART
value|(2L<<16)
end_define

begin_define
define|#
directive|define
name|scm_tc_dblr
value|(scm_tc16_flo|REAL_PART)
end_define

begin_define
define|#
directive|define
name|scm_tc_dblc
value|(scm_tc16_flo|REAL_PART|IMAG_PART)
end_define

begin_define
define|#
directive|define
name|scm_tc16_bigpos
value|0x027f
end_define

begin_define
define|#
directive|define
name|scm_tc16_bigneg
value|0x037f
end_define

begin_define
define|#
directive|define
name|scm_tc16_fport
value|(scm_tc7_port + 0*256L)
end_define

begin_define
define|#
directive|define
name|scm_tc16_pipe
value|(scm_tc7_port + 1*256L)
end_define

begin_define
define|#
directive|define
name|scm_tc16_strport
value|(scm_tc7_port + 2*256L)
end_define

begin_define
define|#
directive|define
name|scm_tc16_sfport
value|(scm_tc7_port + 3*256L)
end_define

begin_comment
comment|/* For cons pairs with immediate values in the CAR */
end_comment

begin_define
define|#
directive|define
name|scm_tcs_cons_imcar
value|2:case 4:case 6:case 10:\  case 12:case 14:case 18:case 20:\  case 22:case 26:case 28:case 30:\  case 34:case 36:case 38:case 42:\  case 44:case 46:case 50:case 52:\  case 54:case 58:case 60:case 62:\  case 66:case 68:case 70:case 74:\  case 76:case 78:case 82:case 84:\  case 86:case 90:case 92:case 94:\  case 98:case 100:case 102:case 106:\  case 108:case 110:case 114:case 116:\  case 118:case 122:case 124:case 126
end_define

begin_comment
comment|/* For cons pairs with non-immediate values in the CAR */
end_comment

begin_define
define|#
directive|define
name|scm_tcs_cons_nimcar
value|0:case 8:case 16:case 24:\  case 32:case 40:case 48:case 56:\  case 64:case 72:case 80:case 88:\  case 96:case 104:case 112:case 120
end_define

begin_comment
comment|/* A CONS_GLOC occurs in code.  It's CAR is a pointer to the  * CDR of a variable.  The low order bits of the CAR are 001.  * The CDR of the gloc is the code continuation.  */
end_comment

begin_define
define|#
directive|define
name|scm_tcs_cons_gloc
value|1:case 9:case 17:case 25:\  case 33:case 41:case 49:case 57:\  case 65:case 73:case 81:case 89:\  case 97:case 105:case 113:case 121
end_define

begin_define
define|#
directive|define
name|scm_tcs_closures
value|3:case 11:case 19:case 27:\  case 35:case 43:case 51:case 59:\  case 67:case 75:case 83:case 91:\  case 99:case 107:case 115:case 123
end_define

begin_define
define|#
directive|define
name|scm_tcs_subrs
value|scm_tc7_asubr:case scm_tc7_subr_0:case scm_tc7_subr_1:case scm_tc7_cxr:\  case scm_tc7_subr_3:case scm_tc7_subr_2:case scm_tc7_rpsubr:case scm_tc7_subr_1o:\  case scm_tc7_subr_2o:case scm_tc7_lsubr_2:case scm_tc7_lsubr
end_define

begin_define
define|#
directive|define
name|scm_tcs_symbols
value|scm_tc7_ssymbol:case scm_tc7_msymbol
end_define

begin_define
define|#
directive|define
name|scm_tcs_bignums
value|tc16_bigpos:case tc16_bigneg
end_define

begin_escape
end_escape

begin_comment
comment|/* References to objects are of type SCM.  Values may be non-immediate  * (pointers) or immediate (encoded, immutable, scalar values that fit  * in an SCM variable).  */
end_comment

begin_typedef
typedef|typedef
name|long
name|SCM
typedef|;
end_typedef

begin_comment
comment|/* Cray machines have pointers that are incremented once for each word,  * rather than each byte, the 3 most significant bits encode the byte  * within the word.  The following macros deal with this by storing the  * native Cray pointers like the ones that looks like scm expects.  This  * is done for any pointers that might appear in the car of a scm_cell, pointers  * to scm_vector elts, functions,&c are not munged.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_UNICOS
end_ifdef

begin_define
define|#
directive|define
name|SCM2PTR
parameter_list|(
name|x
parameter_list|)
value|((int)(x)>> 3)
end_define

begin_define
define|#
directive|define
name|PTR2SCM
parameter_list|(
name|x
parameter_list|)
value|(((SCM)(x))<< 3)
end_define

begin_define
define|#
directive|define
name|SCM_POINTERS_MUNGED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SCM2PTR
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|PTR2SCM
parameter_list|(
name|x
parameter_list|)
value|((SCM)(x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* def _UNICOS */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Immediate? Predicates   */
end_comment

begin_define
define|#
directive|define
name|SCM_IMP
parameter_list|(
name|x
parameter_list|)
value|(6& (int)(x))
end_define

begin_define
define|#
directive|define
name|SCM_NIMP
parameter_list|(
name|x
parameter_list|)
value|(!SCM_IMP(x))
end_define

begin_escape
end_escape

begin_enum
enum|enum
name|scm_tags
block|{
name|scm_tc8_char
init|=
literal|0xf4
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|SCM_ITAG8
parameter_list|(
name|X
parameter_list|)
value|((int)(X)& 0xff)
end_define

begin_define
define|#
directive|define
name|SCM_MAKE_ITAG8
parameter_list|(
name|X
parameter_list|,
name|TAG
parameter_list|)
value|(((X)<<8) + TAG)
end_define

begin_define
define|#
directive|define
name|SCM_ITAG8_DATA
parameter_list|(
name|X
parameter_list|)
value|((X)>>8)
end_define

begin_escape
end_escape

begin_comment
comment|/* Local Environment Structure  */
end_comment

begin_define
define|#
directive|define
name|SCM_ILOCP
parameter_list|(
name|n
parameter_list|)
value|((0xff& (int)(n))==0xfc)
end_define

begin_define
define|#
directive|define
name|SCM_ILOC00
value|(0x000000fcL)
end_define

begin_define
define|#
directive|define
name|SCM_IDINC
value|(0x00100000L)
end_define

begin_define
define|#
directive|define
name|SCM_ICDR
value|(0x00080000L)
end_define

begin_define
define|#
directive|define
name|SCM_IFRINC
value|(0x00000100L)
end_define

begin_define
define|#
directive|define
name|SCM_IDSTMSK
value|(-SCM_IDINC)
end_define

begin_define
define|#
directive|define
name|SCM_IFRAME
parameter_list|(
name|n
parameter_list|)
value|((int)((SCM_ICDR-SCM_IFRINC)>>8)& ((int)(n)>>8))
end_define

begin_define
define|#
directive|define
name|SCM_IDIST
parameter_list|(
name|n
parameter_list|)
value|(((unsigned long)(n))>>20)
end_define

begin_define
define|#
directive|define
name|SCM_ICDRP
parameter_list|(
name|n
parameter_list|)
value|(SCM_ICDR& (n))
end_define

begin_escape
end_escape

begin_comment
comment|/* Immediate Symbols, Special Symbols, Flags (various constants).  */
end_comment

begin_comment
comment|/* ISYMP tests for ISPCSYM and ISYM */
end_comment

begin_define
define|#
directive|define
name|SCM_ISYMP
parameter_list|(
name|n
parameter_list|)
value|((0x187& (int)(n))==4)
end_define

begin_comment
comment|/* IFLAGP tests for ISPCSYM, ISYM and IFLAG */
end_comment

begin_define
define|#
directive|define
name|SCM_IFLAGP
parameter_list|(
name|n
parameter_list|)
value|((0x87& (int)(n))==4)
end_define

begin_define
define|#
directive|define
name|SCM_ISYMNUM
parameter_list|(
name|n
parameter_list|)
value|((int)((n)>>9))
end_define

begin_define
define|#
directive|define
name|SCM_ISYMCHARS
parameter_list|(
name|n
parameter_list|)
value|(scm_isymnames[SCM_ISYMNUM(n)])
end_define

begin_define
define|#
directive|define
name|SCM_MAKSPCSYM
parameter_list|(
name|n
parameter_list|)
value|(((n)<<9)+((n)<<3)+4L)
end_define

begin_define
define|#
directive|define
name|SCM_MAKISYM
parameter_list|(
name|n
parameter_list|)
value|(((n)<<9)+0x74L)
end_define

begin_define
define|#
directive|define
name|SCM_MAKIFLAG
parameter_list|(
name|n
parameter_list|)
value|(((n)<<9)+0x174L)
end_define

begin_comment
comment|/* This table must agree with the declarations   * in repl.c: {Names of immediate symbols}.  *  * These are used only in eval but their values  * have to be allocated here.  *  */
end_comment

begin_define
define|#
directive|define
name|SCM_IM_AND
value|SCM_MAKSPCSYM(0)
end_define

begin_define
define|#
directive|define
name|SCM_IM_BEGIN
value|SCM_MAKSPCSYM(1)
end_define

begin_define
define|#
directive|define
name|SCM_IM_CASE
value|SCM_MAKSPCSYM(2)
end_define

begin_define
define|#
directive|define
name|SCM_IM_COND
value|SCM_MAKSPCSYM(3)
end_define

begin_define
define|#
directive|define
name|SCM_IM_DO
value|SCM_MAKSPCSYM(4)
end_define

begin_define
define|#
directive|define
name|SCM_IM_IF
value|SCM_MAKSPCSYM(5)
end_define

begin_define
define|#
directive|define
name|SCM_IM_LAMBDA
value|SCM_MAKSPCSYM(6)
end_define

begin_define
define|#
directive|define
name|SCM_IM_LET
value|SCM_MAKSPCSYM(7)
end_define

begin_define
define|#
directive|define
name|SCM_IM_LETSTAR
value|SCM_MAKSPCSYM(8)
end_define

begin_define
define|#
directive|define
name|SCM_IM_LETREC
value|SCM_MAKSPCSYM(9)
end_define

begin_define
define|#
directive|define
name|SCM_IM_OR
value|SCM_MAKSPCSYM(10)
end_define

begin_define
define|#
directive|define
name|SCM_IM_QUOTE
value|SCM_MAKSPCSYM(11)
end_define

begin_define
define|#
directive|define
name|SCM_IM_SET
value|SCM_MAKSPCSYM(12)
end_define

begin_define
define|#
directive|define
name|SCM_IM_DEFINE
value|SCM_MAKSPCSYM(13)
end_define

begin_define
define|#
directive|define
name|SCM_IM_APPLY
value|SCM_MAKISYM(14)
end_define

begin_define
define|#
directive|define
name|SCM_IM_CONT
value|SCM_MAKISYM(15)
end_define

begin_define
define|#
directive|define
name|SCM_NUM_ISYMS
value|16
end_define

begin_comment
comment|/* Important immediates  */
end_comment

begin_define
define|#
directive|define
name|SCM_BOOL_F
value|SCM_MAKIFLAG(SCM_NUM_ISYMS+0)
end_define

begin_define
define|#
directive|define
name|SCM_BOOL_T
value|SCM_MAKIFLAG(SCM_NUM_ISYMS+1)
end_define

begin_define
define|#
directive|define
name|SCM_UNDEFINED
value|SCM_MAKIFLAG(SCM_NUM_ISYMS+2)
end_define

begin_define
define|#
directive|define
name|SCM_EOF_VAL
value|SCM_MAKIFLAG(SCM_NUM_ISYMS+3)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SICP
end_ifdef

begin_define
define|#
directive|define
name|SCM_EOL
value|SCM_BOOL_F
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SCM_EOL
value|SCM_MAKIFLAG(SCM_NUM_ISYMS+4)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SCM_UNSPECIFIED
value|SCM_MAKIFLAG(SCM_NUM_ISYMS+5)
end_define

begin_escape
end_escape

begin_comment
comment|/* Heap Pairs and the Empty List Predicates  */
end_comment

begin_define
define|#
directive|define
name|SCM_NULLP
parameter_list|(
name|x
parameter_list|)
value|(SCM_EOL == (x))
end_define

begin_define
define|#
directive|define
name|SCM_NNULLP
parameter_list|(
name|x
parameter_list|)
value|(SCM_EOL != (x))
end_define

begin_define
define|#
directive|define
name|SCM_CELLP
parameter_list|(
name|x
parameter_list|)
value|(!SCM_NCELLP(x))
end_define

begin_define
define|#
directive|define
name|SCM_NCELLP
parameter_list|(
name|x
parameter_list|)
value|((sizeof(scm_cell)-1)& (int)(x))
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|SCM_UNBNDP
parameter_list|(
name|x
parameter_list|)
value|(SCM_UNDEFINED==(x))
end_define

begin_escape
end_escape

begin_comment
comment|/* Testing and Changing GC Marks in Various Standard Positions  */
end_comment

begin_define
define|#
directive|define
name|SCM_GCMARKP
parameter_list|(
name|x
parameter_list|)
value|(1& (int)SCM_CDR(x))
end_define

begin_define
define|#
directive|define
name|SCM_GC8MARKP
parameter_list|(
name|x
parameter_list|)
value|(0x80& (int)SCM_CAR(x))
end_define

begin_define
define|#
directive|define
name|SCM_SETGCMARK
parameter_list|(
name|x
parameter_list|)
value|(SCM_CDR(x) |= 1)
end_define

begin_define
define|#
directive|define
name|SCM_CLRGCMARK
parameter_list|(
name|x
parameter_list|)
value|(SCM_CDR(x)&= ~1L)
end_define

begin_define
define|#
directive|define
name|SCM_SETGC8MARK
parameter_list|(
name|x
parameter_list|)
value|(SCM_CAR(x) |= 0x80)
end_define

begin_define
define|#
directive|define
name|SCM_CLRGC8MARK
parameter_list|(
name|x
parameter_list|)
value|(SCM_CAR(x)&= ~0x80L)
end_define

begin_escape
end_escape

begin_comment
comment|/* Extracting Tag Bits, With or Without GC Safety and Optional Bits  */
end_comment

begin_define
define|#
directive|define
name|SCM_TYP3
parameter_list|(
name|x
parameter_list|)
value|(7& (int)SCM_CAR(x))
end_define

begin_define
define|#
directive|define
name|SCM_TYP7
parameter_list|(
name|x
parameter_list|)
value|(0x7f& (int)SCM_CAR(x))
end_define

begin_define
define|#
directive|define
name|SCM_TYP7S
parameter_list|(
name|x
parameter_list|)
value|(0x7d& (int)SCM_CAR(x))
end_define

begin_define
define|#
directive|define
name|SCM_TYP16
parameter_list|(
name|x
parameter_list|)
value|(0xffff& (int)SCM_CAR(x))
end_define

begin_define
define|#
directive|define
name|SCM_TYP16S
parameter_list|(
name|x
parameter_list|)
value|(0xfeff& (int)SCM_CAR(x))
end_define

begin_define
define|#
directive|define
name|SCM_GCTYP16
parameter_list|(
name|x
parameter_list|)
value|(0xff7f& (int)SCM_CAR(x))
end_define

begin_escape
end_escape

begin_comment
comment|/* Two slightly extensible types: smobs and ptobs.  *  */
end_comment

begin_define
define|#
directive|define
name|SCM_SMOBNUM
parameter_list|(
name|x
parameter_list|)
value|(0x0ff& (CAR(x)>>8));
end_define

begin_define
define|#
directive|define
name|SCM_PTOBNUM
parameter_list|(
name|x
parameter_list|)
value|(0x0ff& (CAR(x)>>8));
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|SCM_DIRP
parameter_list|(
name|x
parameter_list|)
value|(SCM_NIMP(x)&& (TYP16(x)==(scm_tc16_dir)))
end_define

begin_define
define|#
directive|define
name|SCM_OPDIRP
parameter_list|(
name|x
parameter_list|)
value|(SCM_NIMP(x)&& (CAR(x)==(scm_tc16_dir | OPN)))
end_define

begin_escape
end_escape

begin_comment
comment|/* Lvectors   */
end_comment

begin_define
define|#
directive|define
name|SCM_LVECTORP
parameter_list|(
name|x
parameter_list|)
value|(TYP7(x)==tc7_lvector)
end_define

begin_escape
end_escape

begin_if
if|#
directive|if
literal|0
end_if

begin_escape
end_escape

begin_comment
comment|/* Sockets   */
end_comment

begin_define
define|#
directive|define
name|tc_socket
value|(tc7_port | OPN)
end_define

begin_define
define|#
directive|define
name|SCM_SOCKP
parameter_list|(
name|x
parameter_list|)
value|(((0x7f | OPN | RDNG | WRTNG)& CAR(x))==(tc_socket))
end_define

begin_define
define|#
directive|define
name|SCM_SOCKTYP
parameter_list|(
name|x
parameter_list|)
value|(CAR(x)>>24)
end_define

begin_escape
end_escape

begin_define
unit|extern int scm_tc16_key_vector;
define|#
directive|define
name|SCM_KEYVECP
parameter_list|(
name|X
parameter_list|)
value|(scm_tc16_key_vector == TYP16 (X))
end_define

begin_define
define|#
directive|define
name|SCM_KEYVECLEN
parameter_list|(
name|OBJ
parameter_list|)
value|(((unsigned long)CAR (obj))>> 16)
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|SCM_MALLOCDATA
parameter_list|(
name|obj
parameter_list|)
value|((char *)CDR(obj))
end_define

begin_define
define|#
directive|define
name|SCM_MALLOCLEN
parameter_list|(
name|obj
parameter_list|)
value|(((unsigned long)CAR (obj))>> 16)
end_define

begin_define
define|#
directive|define
name|SCM_WORDDATA
parameter_list|(
name|obj
parameter_list|)
value|(CDR (obj))
end_define

begin_define
define|#
directive|define
name|SCM_BYTECODEP
parameter_list|(
name|X
parameter_list|)
value|((TYP7 (X) == tc7_cclo)&& (CCLO_SUBR (X) == rb_proc))
end_define

begin_define
define|#
directive|define
name|SCM_BYTECODE_CONSTANTS
parameter_list|(
name|X
parameter_list|)
value|(VELTS(X)[1])
end_define

begin_define
define|#
directive|define
name|SCM_BYTECODE_CODE
parameter_list|(
name|X
parameter_list|)
value|(VELTS(X)[2])
end_define

begin_define
define|#
directive|define
name|SCM_BYTECODE_NAME
parameter_list|(
name|X
parameter_list|)
value|(VELTS(X)[3])
end_define

begin_define
define|#
directive|define
name|SCM_BYTECODE_BCODE
parameter_list|(
name|X
parameter_list|)
value|(VELTS(X)[4])
end_define

begin_define
define|#
directive|define
name|SCM_BYTECODE_ELTS
value|5
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|SCM_FREEP
parameter_list|(
name|x
parameter_list|)
value|(CAR(x)==tc_free_cell)
end_define

begin_define
define|#
directive|define
name|SCM_NFREEP
parameter_list|(
name|x
parameter_list|)
value|(!FREEP(x))
end_define

begin_escape
end_escape

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0*/
end_comment

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* STDC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STDC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TAGSH */
end_comment

end_unit

