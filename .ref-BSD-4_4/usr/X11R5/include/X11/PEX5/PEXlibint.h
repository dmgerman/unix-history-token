begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: PEXlibint.h,v 1.8 92/08/26 13:05:15 mor Exp $ */
end_comment

begin_comment
comment|/****************************************************************************** Copyright 1987,1991 by Digital Equipment Corporation, Maynard, Massachusetts Copyright 1992 by the Massachusetts Institute of Technology                          All Rights Reserved  Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of Digital or M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  Digital and M.I.T. make no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty.  DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. ******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PEXLIBINT_H
end_ifndef

begin_define
define|#
directive|define
name|PEXLIBINT_H
end_define

begin_include
include|#
directive|include
file|<X11/Xlibint.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xfuncs.h>
end_include

begin_include
include|#
directive|include
file|"PEXproto.h"
end_include

begin_escape
end_escape

begin_comment
comment|/* -------------------------------------------------------------------------  * Typedefs for referencing fields in requests.   * ------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*  * Generic request header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pexRequestHeader
block|{
name|unsigned
name|char
name|extOpcode
decl_stmt|;
name|unsigned
name|char
name|pexOpcode
decl_stmt|;
name|unsigned
name|short
name|reqLength
decl_stmt|;
block|}
name|pexRequestHeader
typedef|;
end_typedef

begin_comment
comment|/*  * OC request header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pexOCRequestHeader
block|{
name|unsigned
name|char
name|extOpcode
decl_stmt|;
name|unsigned
name|char
name|pexOpcode
decl_stmt|;
name|unsigned
name|short
name|reqLength
decl_stmt|;
name|unsigned
name|short
name|fpFormat
decl_stmt|;
name|unsigned
name|short
name|pad
decl_stmt|;
name|unsigned
name|long
name|target
decl_stmt|;
name|unsigned
name|long
name|numCommands
decl_stmt|;
block|}
name|pexOCRequestHeader
typedef|;
end_typedef

begin_comment
comment|/*  * Element header for OC with list.  */
end_comment

begin_typedef
typedef|typedef
name|pexElementInfo
name|pexOCListHeader
typedef|;
end_typedef

begin_comment
comment|/*  * Element header for OC with list& count.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pexOCcListHeader
block|{
name|pexElementInfo
name|head
decl_stmt|;
name|unsigned
name|short
name|length
decl_stmt|;
name|unsigned
name|short
name|pad
decl_stmt|;
block|}
name|pexOCcListHeader
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* -------------------------------------------------------------------------  * Display extension data structures and macros.  * ------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*  * For each display initialized by PEXInitialize(), a record is allocated  * which holds various information about that display.  These records are  * maintained in a linked list.  The record for the most recently referenced  * display is always kept at the beginning of the list (for quick access).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|PEXDisplayInfo
block|{
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* pointer to X display structure */
name|XExtCodes
modifier|*
name|extCodes
decl_stmt|;
comment|/* extension codes */
name|PEXExtensionInfo
modifier|*
name|extInfo
decl_stmt|;
comment|/* extension info */
name|unsigned
name|char
name|extOpcode
decl_stmt|;
comment|/* opcode for pex extension */
name|unsigned
name|short
name|fpFormat
decl_stmt|;
comment|/* floating point format */
name|char
name|fpConvert
decl_stmt|;
comment|/* flag for floating point conversion */
name|PEXEnumTypeDesc
modifier|*
name|fpSupport
decl_stmt|;
comment|/* float formats supported by server */
name|int
name|fpCount
decl_stmt|;
comment|/* number of float formats supported */
name|XID
name|lastResID
decl_stmt|;
comment|/* renderer/structure ID of last OC */
name|int
name|lastReqType
decl_stmt|;
comment|/* request type (store/rend) of last OC */
name|int
name|lastReqNum
decl_stmt|;
comment|/* request number of last OC */
name|struct
name|PEXDisplayInfo
modifier|*
name|next
decl_stmt|;
comment|/* next in list */
block|}
name|PEXDisplayInfo
typedef|;
end_typedef

begin_comment
comment|/*  * Pointer to head of list is defined externally.  */
end_comment

begin_decl_stmt
specifier|extern
name|PEXDisplayInfo
modifier|*
name|PEXDisplayInfoHeader
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Insert a new record in the beginning of the linked list.  */
end_comment

begin_define
define|#
directive|define
name|PEXAddDisplayInfo
parameter_list|(
name|_display
parameter_list|,
name|_info
parameter_list|)
define|\ \
value|{ \     _info->display = _display; \ \     _info->next = PEXDisplayInfoHeader; \     PEXDisplayInfoHeader = _info; \ }
end_define

begin_comment
comment|/*  * Remove the record assosicated with '_display' from the linked list  * and return a pointer to it in '_info'.  */
end_comment

begin_define
define|#
directive|define
name|PEXRemoveDisplayInfo
parameter_list|(
name|_display
parameter_list|,
name|_info
parameter_list|)
define|\ \
value|{ \     PEXDisplayInfo	*prev = NULL; \ \     _info = PEXDisplayInfoHeader; \ \     while (_info&& _info->display != _display) \     { \ 	prev = _info; \ 	_info = _info->next; \     } \ \     if (_info) \ 	if (!prev) \ 	    PEXDisplayInfoHeader = _info->next; \ 	else \ 	    prev->next = _info->next; \ }
end_define

begin_comment
comment|/*  * Return the info assosicated with '_display' in '_info'.  * If the info is not the first in the list, move it to the front.  */
end_comment

begin_define
define|#
directive|define
name|PEXGetDisplayInfo
parameter_list|(
name|_display
parameter_list|,
name|_info
parameter_list|)
define|\ \
value|{ \     _info = PEXDisplayInfoHeader; \ \     if (PEXDisplayInfoHeader->display != _display) \     { \ 	PEXDisplayInfo	*prev = PEXDisplayInfoHeader; \ \ 	_info = _info->next; \ 	while (_info&& _info->display != _display) \ 	{ \ 	    prev = _info; \ 	    _info = _info->next; \ 	} \ \ 	if (_info) \ 	{ \ 	    prev->next = _info->next; \ 	    _info->next = PEXDisplayInfoHeader; \ 	    PEXDisplayInfoHeader = _info; \ 	} \     } \ }
end_define

begin_escape
end_escape

begin_comment
comment|/* -------------------------------------------------------------------------  * Memory related macros.  * ------------------------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|PEXAllocBuf
parameter_list|(
name|size
parameter_list|)
value|Xmalloc(size)
end_define

begin_define
define|#
directive|define
name|PEXFreeBuf
parameter_list|(
name|ptr
parameter_list|)
value|Xfree(ptr)
end_define

begin_define
define|#
directive|define
name|PEXReallocBuf
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|)
value|Xrealloc(ptr, size)
end_define

begin_define
define|#
directive|define
name|COPY_AREA
parameter_list|(
name|_from
parameter_list|,
name|_to
parameter_list|,
name|_size
parameter_list|)
define|\
value|bcopy (_from, _to, _size)
end_define

begin_define
define|#
directive|define
name|COPY_SMALL_AREA
parameter_list|(
name|_from
parameter_list|,
name|_to
parameter_list|,
name|_size
parameter_list|)
define|\
value|{ \     register char *_f = (char *) (_from), *_t = (char *) (_to); \     register int _c = (_size); \     while (--_c>= 0) *_t++ = *_f++; \ }
end_define

begin_define
define|#
directive|define
name|PAD
parameter_list|(
name|_size
parameter_list|)
value|(3 - (((_size) + 3)& 0x3))
end_define

begin_define
define|#
directive|define
name|PADDED_BYTES
parameter_list|(
name|_bytes
parameter_list|)
value|(_bytes + PAD (_bytes))
end_define

begin_define
define|#
directive|define
name|NUMWORDS
parameter_list|(
name|_size
parameter_list|)
value|(((unsigned int)((_size) + 3))>> 2)
end_define

begin_define
define|#
directive|define
name|NUMBYTES
parameter_list|(
name|_len
parameter_list|)
value|(((unsigned int)(_len))<< 2)
end_define

begin_define
define|#
directive|define
name|LENOF
parameter_list|(
name|_ctype
parameter_list|)
value|(sizeof (_ctype)>> 2)
end_define

begin_comment
comment|/*   * Count the number of ones in a longword.  */
end_comment

begin_define
define|#
directive|define
name|CountOnes
parameter_list|(
name|mask
parameter_list|,
name|countReturn
parameter_list|)
define|\
value|countReturn = ((mask) - (((mask)>>1)&0x77777777) \ 	- (((mask)>>2)&0x33333333) - (((mask)>>3)&0x11111111)); \     countReturn = ((((countReturn)+((countReturn)>>4))& 0x0F0F0F0F) % 255)
end_define

begin_escape
end_escape

begin_comment
comment|/* -------------------------------------------------------------------------  * Macros for dealing with the transport buffer.   * ------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*  * The maximum protocol request size.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REQUEST_SIZE
value|((1<<16) - 1)
end_define

begin_comment
comment|/*  * Has the X transport buffer been flushed?  */
end_comment

begin_define
define|#
directive|define
name|XBufferFlushed
parameter_list|(
name|_display
parameter_list|)
define|\
value|((_display)->buffer == (_display)->bufptr)
end_define

begin_comment
comment|/*  * The number of bytes left in the X transport buffer.  */
end_comment

begin_define
define|#
directive|define
name|BytesLeftInXBuffer
parameter_list|(
name|_display
parameter_list|)
define|\
value|((_display)->bufmax - (_display)->bufptr)
end_define

begin_comment
comment|/*  * The number of words left in the X transport buffer.  */
end_comment

begin_define
define|#
directive|define
name|WordsLeftInXBuffer
parameter_list|(
name|_display
parameter_list|)
define|\
value|(((_display)->bufmax - (_display)->bufptr)>> 2)
end_define

begin_comment
comment|/*  * Setup the OC element info header.  */
end_comment

begin_define
define|#
directive|define
name|STORE_ELEMENT_INFO
parameter_list|(
name|_reqPtr
parameter_list|,
name|_ocType
parameter_list|,
name|_ocLength
parameter_list|)
define|\
value|{ \     ((pexElementInfo *)(_reqPtr))->elementType = (_ocType); \     ((pexElementInfo *)(_reqPtr))->length = (_ocLength); \ }
end_define

begin_comment
comment|/*   * PEXGetReq sets up a request to be sent to the X server.  If there isn't  * enough room left in the X buffer, it is flushed before the new request  * is started.  *  * PEXGetFPReq is similar to PEXGetReq, except that it sets up a request  * that contains floating point values.  A return flag indicates whether  * or not the client native floating point format has to be converted to  * a server supported format.  *  * SETUP_REQ is a macro containing common code for PEXGetReq and PEXGetFPReq.  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
operator|&&
operator|!
name|defined
argument_list|(
name|UNIXCPP
argument_list|)
end_if

begin_define
define|#
directive|define
name|SETUP_REQ
parameter_list|(
name|_name
parameter_list|,
name|_req
parameter_list|)
define|\
value|PEXDisplayInfo *pexDisplayInfo; \     PEXGetDisplayInfo (display, pexDisplayInfo); \     if ((display->bufptr + sizeof (pex##_name##Req))> display->bufmax) \         _XFlush (display); \     _req = (pex##_name##Req *) (display->last_req = display->bufptr); \     _req->reqType = pexDisplayInfo->extOpcode; \     _req->opcode = PEXRC##_name; \     _req->length = (sizeof (pex##_name##Req))>> 2; \     display->bufptr += sizeof (pex##_name##Req); \     display->request++
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* non-ANSI C uses empty comment instead of "##" for token concat */
end_comment

begin_define
define|#
directive|define
name|SETUP_REQ
parameter_list|(
name|_name
parameter_list|,
name|_req
parameter_list|)
define|\
value|PEXDisplayInfo *pexDisplayInfo; \     PEXGetDisplayInfo (display, pexDisplayInfo); \     if ((display->bufptr + sizeof (pex
comment|/**/
value|_name
comment|/**/
value|Req))> display->bufmax) \         _XFlush (display); \     _req = (pex
comment|/**/
value|_name
comment|/**/
value|Req *) (display->last_req = display->bufptr); \     _req->reqType = pexDisplayInfo->extOpcode; \     _req->opcode = PEXRC
comment|/**/
value|_name; \     _req->length = (sizeof (pex
comment|/**/
value|_name
comment|/**/
value|Req))>> 2; \     display->bufptr += sizeof (pex
comment|/**/
value|_name
comment|/**/
value|Req); \     display->request++
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PEXGetReq
parameter_list|(
name|_name
parameter_list|,
name|_req
parameter_list|)
define|\
value|{ \     SETUP_REQ (_name, _req); \ }
end_define

begin_define
define|#
directive|define
name|PEXGetFPReq
parameter_list|(
name|_name
parameter_list|,
name|_req
parameter_list|,
name|_fpConvert
parameter_list|)
define|\
value|{ \     SETUP_REQ (_name, _req); \     _req->fpFormat = pexDisplayInfo->fpFormat; \     _fpConvert = pexDisplayInfo->fpConvert; \ }
end_define

begin_comment
comment|/*   * PEXGetReqExtra and PEXGetFPReqExtra are the same as PEXGetReq and  * PEXGetFPReq, except that an additional "n" bytes are allocated after  * the request.  "n" will be padded to a word boundary.  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
operator|&&
operator|!
name|defined
argument_list|(
name|UNIXCPP
argument_list|)
end_if

begin_define
define|#
directive|define
name|SETUP_REQ_EXTRA
parameter_list|(
name|_name
parameter_list|,
name|_n
parameter_list|,
name|_req
parameter_list|)
define|\
value|PEXDisplayInfo *pexDisplayInfo; \     PEXGetDisplayInfo (display, pexDisplayInfo); \     if ((display->bufptr + sizeof (pex##_name##Req) + PADDED_BYTES (_n))>\         display->bufmax) \         _XFlush (display); \     _req = (pex##_name##Req *) (display->last_req = display->bufptr); \     _req->reqType = pexDisplayInfo->extOpcode; \     _req->opcode = PEXRC##_name; \     _req->length = (sizeof(pex##_name##Req) + PADDED_BYTES (_n))>> 2; \     display->bufptr += sizeof (pex##_name##Req) + PADDED_BYTES (_n); \     display->request++
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* non-ANSI C uses empty comment instead of "##" for token concat */
end_comment

begin_define
define|#
directive|define
name|SETUP_REQ_EXTRA
parameter_list|(
name|_name
parameter_list|,
name|_n
parameter_list|,
name|_req
parameter_list|)
define|\
value|PEXDisplayInfo *pexDisplayInfo; \     PEXGetDisplayInfo (display, pexDisplayInfo); \     if ((display->bufptr + sizeof (pex
comment|/**/
value|_name
comment|/**/
value|Req) + PADDED_BYTES (_n))>\         display->bufmax) \         _XFlush (display); \     _req = (pex
comment|/**/
value|_name
comment|/**/
value|Req *) (display->last_req = display->bufptr); \     _req->reqType = pexDisplayInfo->extOpcode; \     _req->opcode = PEXRC
comment|/**/
value|_name; \     _req->length = (sizeof(pex
comment|/**/
value|_name
comment|/**/
value|Req) + PADDED_BYTES (_n))>> 2; \     display->bufptr += sizeof (pex
comment|/**/
value|_name
comment|/**/
value|Req) + PADDED_BYTES (_n); \     display->request++
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PEXGetReqExtra
parameter_list|(
name|_name
parameter_list|,
name|_n
parameter_list|,
name|_req
parameter_list|)
define|\
value|{ \     SETUP_REQ_EXTRA (_name, _n, _req); \ }
end_define

begin_define
define|#
directive|define
name|PEXGetFPReqExtra
parameter_list|(
name|_name
parameter_list|,
name|_n
parameter_list|,
name|_req
parameter_list|,
name|_fpConvert
parameter_list|)
define|\
value|{ \     SETUP_REQ_EXTRA (_name, _n, _req); \     _req->fpFormat = pexDisplayInfo->fpFormat; \     _fpConvert = pexDisplayInfo->fpConvert; \ }
end_define

begin_comment
comment|/*  * PEXGetOCReq is similiar to PEXGetReq except that it does not update  * display->bufptr.  This is used when writing ocs into the transport buffer.  */
end_comment

begin_define
define|#
directive|define
name|PEXGetOCReq
parameter_list|(
name|_display
parameter_list|,
name|_nBytes
parameter_list|)
define|\
value|{ \     if ((_display)->bufptr + (_nBytes)> (_display)->bufmax) \         _XFlush (_display); \     (_display)->last_req = (_display)->bufptr; \     (_display)->request++; \ }
end_define

begin_comment
comment|/*   * See if XSynchronize has been called.  If so, send request right away.  */
end_comment

begin_define
define|#
directive|define
name|PEXSyncHandle
parameter_list|(
name|_display
parameter_list|)
define|\
value|if ((_display)->synchandler) (*(_display)->synchandler) (_display)
end_define

begin_escape
end_escape

begin_comment
comment|/* -------------------------------------------------------------------------  * Color related macros.  * ------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*   * Return the size of the color in bytes by looking at the color type.    * Note that the size of an indexed color is pre-padded to a word boundary.  */
end_comment

begin_define
define|#
directive|define
name|GetColorSize
parameter_list|(
name|_type
parameter_list|)
define|\
value|((_type) == PEXColorTypeIndexed ? (sizeof (pexTableIndex) * 2) : \     ((_type) == PEXColorTypeRGB8 ? sizeof (pexRgb8Color) : \     ((_type) == PEXColorTypeRGB16 ? sizeof (pexRgb16Color) : \ 	sizeof (pexRgbFloatColor))))
end_define

begin_comment
comment|/*  * Return the number of words in a color.  Note that all the PEX color  * types are padded to end on a word boundary  */
end_comment

begin_define
define|#
directive|define
name|GetColorLength
parameter_list|(
name|_type_
parameter_list|)
define|\
value|((_type_) == PEXColorTypeIndexed ?  LENOF( PEXColorIndexed) :\     ((_type_) == PEXColorTypeRGB8 ?  LENOF( PEXColorRGB8) :\     ((_type_) == PEXColorTypeRGB16 ? LENOF( PEXColorRGB16) : \ 					LENOF( PEXColorRGB) )))
end_define

begin_comment
comment|/*   * How big, relative to the largest color specifier, is the color?  * The users of this macro must subtract this value from the sizeof value.  */
end_comment

begin_define
define|#
directive|define
name|AdjustSizeFromType
parameter_list|(
name|_type
parameter_list|)
define|\
value|(sizeof (pexColor) - GetColorSize (_type))
end_define

begin_comment
comment|/*   * Initialize a color specifier.  'dst' is of type PEXColorSpecifier,  * and 'src' is of type PEXColor.  */
end_comment

begin_define
define|#
directive|define
name|InitializeColorSpecifier
parameter_list|(
name|_dst
parameter_list|,
name|_src
parameter_list|,
name|_type
parameter_list|)
define|\
value|(_dst).type = _type; \     COPY_SMALL_AREA ((_src),&((_dst).value), GetColorSize (_type));
end_define

begin_comment
comment|/*  * PackColorSpecifier is similar to InitalizeColorSpecifier, except that  * the destination is a pointer to memory, rather than a static structure.  */
end_comment

begin_define
define|#
directive|define
name|PackColorSpecifier
parameter_list|(
name|srcBuf
parameter_list|,
name|dstBuf
parameter_list|,
name|sizeColor
parameter_list|)
define|\
value|{ \     ((PEXColorSpecifier *) (dstBuf))->type = \         ((PEXColorSpecifier *) (srcBuf))->type; \     sizeColor = \         GetColorSize (((PEXColorSpecifier *) (srcBuf))->type); \     COPY_SMALL_AREA (&(((PEXColorSpecifier *) (srcBuf))->value), \&(((PEXColorSpecifier *) (dstBuf))->value), sizeColor); \ }
end_define

begin_escape
end_escape

begin_comment
comment|/* -------------------------------------------------------------------------  * Macros to compute the number of words in a facet/vertex with data.  * ------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*  * Compute the number of words in the facet data  */
end_comment

begin_define
define|#
directive|define
name|GetFacetDataLength
parameter_list|(
name|_fattribs
parameter_list|,
name|_lenofColor
parameter_list|)
define|\
value|(((_fattribs& PEXGAColor) ? _lenofColor : 0) + \     ((_fattribs& PEXGANormal) ? LENOF(pexVector3D) : 0))
end_define

begin_comment
comment|/*  * Compute the number of words in a vertex with optional colors and normals  */
end_comment

begin_define
define|#
directive|define
name|GetVertexWithDataLength
parameter_list|(
name|_vattribs
parameter_list|,
name|_lenofColor
parameter_list|)
define|\
value|(LENOF (pexCoord3D) + \     ((_vattribs& PEXGAColor) ? _lenofColor : 0) + \     ((_vattribs& PEXGANormal) ? LENOF (pexVector3D) : 0))
end_define

begin_escape
end_escape

begin_comment
comment|/* -------------------------------------------------------------------------  * Data structures useful for packing protocol data.  * ------------------------------------------------------------------------- */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|attribute
decl_stmt|;
name|unsigned
name|char
name|value
decl_stmt|;
name|unsigned
name|char
name|reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|PEXASFData
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|fp_format
decl_stmt|;
name|short
name|reserved
decl_stmt|;
name|unsigned
name|long
name|renderer
decl_stmt|;
name|PEXColorSpecifier
name|echo_color
decl_stmt|;
block|}
name|PEXEchoColorData
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* -------------------------------------------------------------------------  * Miscellaneous.  * ------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*  * IEEE-754-32 is the most common floating point type.  Vendors who have  * a different native floating point format should define NATIVE_FP_FORMAT  * at compile time via the -D switch (this is done by modifying the vendors  * config file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NATIVE_FP_FORMAT
end_ifndef

begin_define
define|#
directive|define
name|NATIVE_FP_FORMAT
value|PEXIEEE_754_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * INPUT and OUTPUT are defined to make looking at function arguments easier.  */
end_comment

begin_define
define|#
directive|define
name|INPUT
end_define

begin_define
define|#
directive|define
name|OUTPUT
end_define

begin_define
define|#
directive|define
name|INOUT
end_define

begin_comment
comment|/*  * Pick path cache.  */
end_comment

begin_define
define|#
directive|define
name|MAX_PICK_CACHE_SIZE
value|2048
end_define

begin_decl_stmt
specifier|extern
name|PEXPickPath
modifier|*
name|PEXPickCache
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|PEXPickCacheSize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|PEXPickCacheInUse
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * _XAllocScratch is defined in Xlib.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|_XAllocScratch
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PEXLIBINT_H */
end_comment

end_unit

