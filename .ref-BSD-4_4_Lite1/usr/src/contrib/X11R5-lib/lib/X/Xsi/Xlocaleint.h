begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: Xlocaleint.h,v 1.35 92/04/14 15:55:37 rws Exp $  */
end_comment

begin_comment
comment|/*  * Copyright 1990, 1991 by OMRON Corporation, NTT Software Corporation,  *                      and Nippon Telegraph and Telephone Corporation  * Copyright 1991 by the Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the names of OMRON, NTT Software, NTT, and M.I.T.  * not be used in advertising or publicity pertaining to distribution of the  * software without specific, written prior permission. OMRON, NTT Software,  * NTT, and M.I.T. make no representations about the suitability of this  * software for any purpose.  It is provided "as is" without express or  * implied warranty.  *  * OMRON, NTT SOFTWARE, NTT, AND M.I.T. DISCLAIM ALL WARRANTIES WITH REGARD  * TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS, IN NO EVENT SHALL OMRON, NTT SOFTWARE, NTT, OR M.I.T. BE  * LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES   * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *   *	Authors: Li Yuhong		OMRON Corporation  *		 Tatsuya Kato		NTT Software Corporation  *		 Hiroashi Kuribayashi	OMRON Corporation  *     */
end_comment

begin_comment
comment|/*  *      Xlocaleint.h -- Header definition.  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XLOCALEINT_H_
end_ifndef

begin_define
define|#
directive|define
name|_XLOCALEINT_H_
end_define

begin_define
define|#
directive|define
name|_WCHARXLIB_
end_define

begin_include
include|#
directive|include
file|"wcharint.h"
end_include

begin_undef
undef|#
directive|undef
name|_WCHARXLIB_
end_undef

begin_include
include|#
directive|include
file|<X11/Xlocale.h>
end_include

begin_include
include|#
directive|include
file|"Xlcint.h"
end_include

begin_define
define|#
directive|define
name|MAXCHARSETS
value|16
end_define

begin_define
define|#
directive|define
name|MAXSEQUENCELENGTH
value|255
end_define

begin_define
define|#
directive|define
name|XDEFAULT_STATE
value|0xffffff
end_define

begin_comment
comment|/* to specify default _State for XConvertXXToXX */
end_comment

begin_comment
comment|/*  * Charset id of codeset. Maximun is 10 charsets of one codeset.  * Must Define:  CODESETi = i, other functions will use this convension.  *   */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|_State
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|_CSID
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CODESET0
value|0
end_define

begin_comment
comment|/* Charset 0 */
end_comment

begin_define
define|#
directive|define
name|CODESET1
value|1
end_define

begin_comment
comment|/* Charset 1 */
end_comment

begin_define
define|#
directive|define
name|CODESET2
value|2
end_define

begin_comment
comment|/* Charset 2 */
end_comment

begin_define
define|#
directive|define
name|CODESET3
value|3
end_define

begin_comment
comment|/* Charset 3 */
end_comment

begin_define
define|#
directive|define
name|CODESET4
value|4
end_define

begin_comment
comment|/* Charset 4 */
end_comment

begin_define
define|#
directive|define
name|CODESET5
value|5
end_define

begin_comment
comment|/* Charset 5 */
end_comment

begin_define
define|#
directive|define
name|CODESET6
value|6
end_define

begin_comment
comment|/* Charset 6 */
end_comment

begin_define
define|#
directive|define
name|CODESET7
value|7
end_define

begin_comment
comment|/* Charset 7 */
end_comment

begin_define
define|#
directive|define
name|CODESET8
value|8
end_define

begin_comment
comment|/* Charset 8 */
end_comment

begin_define
define|#
directive|define
name|CODESET9
value|9
end_define

begin_comment
comment|/* Charset 9 */
end_comment

begin_define
define|#
directive|define
name|CODESETA
value|10
end_define

begin_comment
comment|/* Charset A */
end_comment

begin_define
define|#
directive|define
name|CODESETB
value|11
end_define

begin_comment
comment|/* Charset B */
end_comment

begin_define
define|#
directive|define
name|CODESETC
value|12
end_define

begin_comment
comment|/* Charset C */
end_comment

begin_define
define|#
directive|define
name|CODESETD
value|13
end_define

begin_comment
comment|/* Charset D */
end_comment

begin_define
define|#
directive|define
name|CODESETE
value|14
end_define

begin_comment
comment|/* Charset E */
end_comment

begin_define
define|#
directive|define
name|CODESETF
value|15
end_define

begin_comment
comment|/* Charset F */
end_comment

begin_define
define|#
directive|define
name|C0
value|16
end_define

begin_comment
comment|/* Control Set 0 */
end_comment

begin_define
define|#
directive|define
name|C1
value|17
end_define

begin_comment
comment|/* Control Set 1 */
end_comment

begin_define
define|#
directive|define
name|ND
value|127
end_define

begin_comment
comment|/* Not Defined */
end_comment

begin_comment
comment|/* ISO encoding */
end_comment

begin_define
define|#
directive|define
name|GL
value|0
end_define

begin_define
define|#
directive|define
name|GR
value|0x80
end_define

begin_define
define|#
directive|define
name|C94
value|0
end_define

begin_define
define|#
directive|define
name|C96
value|1
end_define

begin_comment
comment|/*  * Type of codeset  */
end_comment

begin_define
define|#
directive|define
name|CDS_STATELESS
value|1
end_define

begin_comment
comment|/* state-independent codeset */
end_comment

begin_define
define|#
directive|define
name|CDS_STATEFUL
value|2
end_define

begin_comment
comment|/* state-dependent codeset */
end_comment

begin_define
define|#
directive|define
name|CDS_SELFDEFINED
value|10
end_define

begin_comment
comment|/* self defined codeset, not used yet.*/
end_comment

begin_comment
comment|/*  * Data Structure for Convert Map List */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|mb_start
decl_stmt|;
comment|/* starting code point of multibyte*/
name|unsigned
name|int
name|mb_end
decl_stmt|;
comment|/* ending code point of multibyte  */
name|unsigned
name|int
name|cs_start
decl_stmt|;
comment|/* starting code point of charset */
name|unsigned
name|int
name|cs_end
decl_stmt|;
comment|/* ending code point of charset  */
block|}
name|Range
typedef|;
end_typedef

begin_comment
comment|/*  * Data Structure for Codeset  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Stateless Codeset */
name|int
name|cds_type
decl_stmt|;
comment|/* stateless type */
name|_CSID
name|cds_num
decl_stmt|;
comment|/* number of charsets */
name|_State
name|mb_init
decl_stmt|;
comment|/* inital designate */
name|int
name|cds_msbon
decl_stmt|;
comment|/* 8bit encoding or not */
name|int
name|cds_mb_cur_max
decl_stmt|;
comment|/* max number of bytes of this codeset */
comment|/* = max(cds_mblen) + max(cds_dsg) */
name|int
name|cds_mblen
index|[
name|MAXCHARSETS
index|]
decl_stmt|;
comment|/* mb length of each charsets */
name|unsigned
name|short
name|cs_offset
index|[
name|MAXCHARSETS
index|]
decl_stmt|;
comment|/* GL or GR */
name|Range
modifier|*
name|cds_cnvlist
decl_stmt|;
comment|/* table-driven conversion list */
name|int
name|cds_cnvindex
index|[
name|MAXCHARSETS
index|]
decl_stmt|;
comment|/* conversion list index */
name|int
function_decl|(
modifier|*
name|cds_cnvproc
function_decl|)
parameter_list|()
function_decl|;
comment|/* procedure-driven conversion, not used */
union|union
block|{
name|_CSID
name|map
index|[
literal|256
index|]
decl_stmt|;
comment|/* charset mapping table,stateless CCS*/
name|char
modifier|*
name|dsg
index|[
name|MAXCHARSETS
index|]
decl_stmt|;
comment|/* designation of charaset,stateful CCS*/
block|}
name|cds
union|;
define|#
directive|define
name|cds_map
value|cds.map
define|#
directive|define
name|cds_dsg
value|cds.dsg
block|}
name|Codeset
typedef|;
end_typedef

begin_comment
comment|/*  * The number of charasets is different from the number of fonts in  * some codeset, e.g., the current UJIS, no extended font for CODESET3.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|cs_name
decl_stmt|;
comment|/* charset name: CharSetReg-CharSetEncoding */
name|wchar
name|cs_woff
decl_stmt|;
comment|/* wchar offset of DP 10646 */
name|int
name|cs_len
decl_stmt|;
comment|/* length in bytes */
name|char
modifier|*
name|cs_des
decl_stmt|;
comment|/* designate sequence of COMPOUND TEXT */
name|_CSID
name|cs_GLorGR
decl_stmt|;
name|_CSID
name|cs_id
decl_stmt|;
comment|/* index of ISOStateTable(_XInitCTEncoding) */
block|}
name|Charset
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|fs_num
decl_stmt|;
comment|/* number of fonts of locale */
name|Charset
modifier|*
modifier|*
name|fs_cset
decl_stmt|;
comment|/* charset encoding */
block|}
name|Fontset
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_XLocaleDB
block|{
name|char
modifier|*
name|lc_name
decl_stmt|;
comment|/* locale name for LC_ALL */
name|char
modifier|*
name|lc_encoding
decl_stmt|;
comment|/* encoding name */
name|Codeset
modifier|*
name|lc_codeset
decl_stmt|;
comment|/* category of codeset */
name|Fontset
modifier|*
name|lc_fontset
decl_stmt|;
comment|/* category of fontset */
name|struct
name|_XLocaleDB
modifier|*
name|next
decl_stmt|;
comment|/* chain pointer */
block|}
name|XLocaleDB
typedef|;
end_typedef

begin_comment
comment|/* the definition for initial state of locale is:      initial state of state-independent codeset:      byte 2         byte 1         byte 0    +-------------+--------------+--------------+    | GL/GR flag  |  CODESET0    |  CODESET0    |    +-------------+--------------+--------------+      initial state of state-dependent codeset:       byte 2         byte 1         byte 0     +-------------+--------------+--------------+     | GL/GR flag  | GR CODESETj  | GL CODESETi  |     +-------------+--------------+--------------+       where: 	GL CODESETi is the first GL encoding of codeset, usually is 	CODESET0. 	GR CODESETj is the first GR encoding of codeset.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XLocaleDB
modifier|*
name|xlc_db
decl_stmt|;
name|char
modifier|*
name|lc_lang
decl_stmt|;
comment|/* locale name */
name|_State
name|ct_state
decl_stmt|;
name|_State
name|mb_state
decl_stmt|;
block|}
name|XLocaleRec
operator|,
typedef|*
name|XLocale
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|XLCdMethods
name|methods
decl_stmt|;
comment|/* methods of this LC */
name|XLCdCoreRec
name|core
decl_stmt|;
comment|/* core data of this LC */
name|XLocale
name|xlc
decl_stmt|;
block|}
name|XsiLCdRec
operator|,
typedef|*
name|XsiLCd
typedef|;
end_typedef

begin_comment
comment|/*   * Data Structure for Charset.  * This charset is designated by escape sequence that is defined in ISO 2022.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|code_bytes
decl_stmt|;
comment|/* number of bytes of 94/96 charset*/
name|unsigned
name|char
name|code_min
decl_stmt|,
comment|/* minimun of all bytes of GL/GR charset */
name|code_max
decl_stmt|;
comment|/* maximun of all bytes of GL/GR charset */
block|}
name|ISOStateInfo
typedef|;
end_typedef

begin_comment
comment|/*  * Must define:  *   Success  = 0  *   BadName< 0  * Some functions will use this convension, e.g., _XwcDecomposeGlyphCharset().  */
end_comment

begin_define
define|#
directive|define
name|BufferOverFlow
value|(-1)
end_define

begin_define
define|#
directive|define
name|BadBuffer
value|(-1)
end_define

begin_define
define|#
directive|define
name|BadTerminate
value|(-2)
end_define

begin_define
define|#
directive|define
name|BadEncoding
value|(-3)
end_define

begin_define
define|#
directive|define
name|_XctDefaultState
parameter_list|()
value|(_State)(CODESET0 | CODESET1<< 8 | GL<< 16)
end_define

begin_define
define|#
directive|define
name|_XmbDefaultState
parameter_list|(
name|xlocale
parameter_list|)
value|((xlocale)->xlc_db->lc_codeset->mb_init)
end_define

begin_define
define|#
directive|define
name|_Xmbtype
parameter_list|(
name|xlocale
parameter_list|)
value|((xlocale)->xlc_db->lc_codeset->cds_type)
end_define

begin_define
define|#
directive|define
name|_Xmbcsnum
parameter_list|(
name|xlocale
parameter_list|)
value|((xlocale)->xlc_db->lc_codeset->cds_num)
end_define

begin_define
define|#
directive|define
name|_Xmbfsnum
parameter_list|(
name|xlocale
parameter_list|)
value|((xlocale)->xlc_db->lc_fontset->fs_num)
end_define

begin_define
define|#
directive|define
name|ctGetGLid
parameter_list|(
name|xlocale
parameter_list|)
value|(_CSID)((xlocale)->ct_state& 0xff)
end_define

begin_define
define|#
directive|define
name|ctGetGRid
parameter_list|(
name|xlocale
parameter_list|)
value|(_CSID)((xlocale)->ct_state>> 8& 0xff)
end_define

begin_define
define|#
directive|define
name|ctGetGLorGR
parameter_list|(
name|xlocale
parameter_list|)
value|(_CSID)((xlocale)->ct_state>> 16& 0xff)
end_define

begin_define
define|#
directive|define
name|ctGetid
parameter_list|(
name|xlocale
parameter_list|)
value|(_CSID)((ctGetGLorGR(xlocale) == GL) ? \ 				 ctGetGLid(xlocale) : ctGetGRid(xlocale))
end_define

begin_define
define|#
directive|define
name|ctSetGLid
parameter_list|(
name|xlocale
parameter_list|,
name|id
parameter_list|)
value|((xlocale)->ct_state = (xlocale)->ct_state& 0xffff00 | (id))
end_define

begin_define
define|#
directive|define
name|ctSetGRid
parameter_list|(
name|xlocale
parameter_list|,
name|id
parameter_list|)
value|((xlocale)->ct_state = \ 				 (xlocale)->ct_state& 0xff00ff | (_State)(id)<< 8)
end_define

begin_define
define|#
directive|define
name|ctSetGLorGR
parameter_list|(
name|xlocale
parameter_list|,
name|id
parameter_list|)
value|((xlocale)->ct_state = \ 				 (xlocale)->ct_state& 0x00ffff | (_State)(id)<< 16)
end_define

begin_define
define|#
directive|define
name|ctSetid
parameter_list|(
name|xlocale
parameter_list|,
name|id
parameter_list|)
value|((xlocale)->ct_state = \ 				 (ctGetGLorGR(xlocale) == GL) ? \ 				 ctSetGLid(xlocale, id) : ctSetGRid(xlocale, id))
end_define

begin_define
define|#
directive|define
name|mbGetGLid
parameter_list|(
name|xlocale
parameter_list|)
value|(_CSID)((xlocale)->mb_state& 0xff)
end_define

begin_define
define|#
directive|define
name|mbGetGRid
parameter_list|(
name|xlocale
parameter_list|)
value|(_CSID)((xlocale)->mb_state>> 8& 0xff)
end_define

begin_define
define|#
directive|define
name|mbGetGLorGR
parameter_list|(
name|xlocale
parameter_list|)
value|(_CSID)((xlocale)->mb_state>> 16& 0xff)
end_define

begin_define
define|#
directive|define
name|mbGetid
parameter_list|(
name|xlocale
parameter_list|)
value|(_CSID)((mbGetGLorGR(xlocale) == GL) ? \ 				 mbGetGLid(xlocale) : mbGetGRid(xlocale))
end_define

begin_define
define|#
directive|define
name|mbSetGLid
parameter_list|(
name|xlocale
parameter_list|,
name|id
parameter_list|)
value|((xlocale)->mb_state = (xlocale)->mb_state& 0xffff00 | (id))
end_define

begin_define
define|#
directive|define
name|mbSetGRid
parameter_list|(
name|xlocale
parameter_list|,
name|id
parameter_list|)
value|((xlocale)->mb_state = \ 				 (xlocale)->mb_state& 0xff00ff | ((_State)(id)<< 8))
end_define

begin_define
define|#
directive|define
name|mbSetGLorGR
parameter_list|(
name|xlocale
parameter_list|,
name|id
parameter_list|)
value|((xlocale)->mb_state = \ 				 (xlocale)->mb_state& 0x00ffff | (_State)(id)<< 16)
end_define

begin_define
define|#
directive|define
name|mbSetid
parameter_list|(
name|xlocale
parameter_list|,
name|id
parameter_list|)
value|((xlocale)->mb_state = \ 				 (mbGetGLorGR(xlocale) == GL) ? \ 				 mbSetGLid(xlocale, id) : mbSetGRid(xlocale, id))
end_define

begin_define
define|#
directive|define
name|_Xctinit
parameter_list|(
name|xlocale
parameter_list|)
value|((xlocale)->ct_state = _XctDefaultState())
end_define

begin_define
define|#
directive|define
name|_Xmbinit
parameter_list|(
name|xlocale
parameter_list|)
value|((xlocale)->mb_state = _XmbDefaultState(xlocale))
end_define

begin_define
define|#
directive|define
name|_XlcFreeLocale
parameter_list|(
name|xlc
parameter_list|)
value|Xfree((char *)(xlc))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_comment
comment|/* I am not yet convinced we need these inside Xlib */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|X_NOT_STDC_ENV
end_ifndef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MB_LEN_MAX
end_ifndef

begin_define
define|#
directive|define
name|MB_LEN_MAX
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|X_NOT_STDC_ENV
end_ifndef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MB_CUR_MAX
end_ifndef

begin_define
define|#
directive|define
name|MB_CUR_MAX
value|(_XFallBackConvert()->xlc_db->lc_codeset->cds_mb_cur_max)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_isXString
parameter_list|(
name|c
parameter_list|)
define|\
value|(((c)>= 0x20&& (c)<= 0x7e) || (c)>= 0xa0 || (c) == 0x09 || (c) == 0x0a)
end_define

begin_comment
comment|/* XlcAccess.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|_Xmbmsbon
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|_CSID
name|_Xmbcsid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_Xmblen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|_Xmbdsg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_Xmbdlen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Charset
modifier|*
name|_Xmbfscs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|_Xmbfsname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_Xmbfslen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|_Xmbfsdsg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|wchar
name|_Xmbfswf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_Xmbctocsc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_Xcsctombc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|_CSID
name|_XmbctGLorGR
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|_CSID
name|_Xmbctid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|_CSID
name|_Xmbctidtocsid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_XmbGetDefaultEncoding
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* XInitCT.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|_XInitCTEncoding
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|_XctisGLdsg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|_XcwNameGetAll
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|_CSID
name|_XcwNameGetGLorGRId
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_XcwGetAll
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_XcwGetDefaultEncoding
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|_CSID
name|_XcwGetWoffsetFromLocale
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|_XcwCheckDefaultState
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|_XmbCheck
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|_XcwIdCheck
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|_XcwIdGetAll
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|_XcwIdGetEncoding
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XcwGetLength
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* XlcLoad.c */
end_comment

begin_function_decl
specifier|extern
name|XLocale
name|_XlcDupLocale
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XLocale
name|_XlcMakeLocale
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XLocale
name|_XFallBackConvert
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XmbDecomposeGlyphCharset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XwcDecomposeGlyphCharset
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XLOCALEINT_H_ */
end_comment

end_unit

