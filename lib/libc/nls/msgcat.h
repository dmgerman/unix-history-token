begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MSGCAT_H_
end_ifndef

begin_define
define|#
directive|define
name|_MSGCAT_H_
end_define

begin_comment
comment|/*********************************************************** Copyright 1990, by Alfalfa Software Incorporated, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that Alfalfa's name not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  ALPHALPHA DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL ALPHALPHA BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  If you make any modifications, bugfixes or other changes to this software we'd appreciate it if you could send a copy to us so we can keep things up-to-date.  Many thanks. 				Kee Hinckley 				Alfalfa Software, Inc. 				267 Allston St., #3 				Cambridge, MA 02139  USA 				nazgul@alfalfa.com  ******************************************************************/
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/*  * On disk data structures  */
end_comment

begin_comment
comment|/* For or'd constants */
end_comment

begin_define
define|#
directive|define
name|MCMakeId
parameter_list|(
name|s
parameter_list|,
name|m
parameter_list|)
value|(unsigned long) ( ((unsigned short)s<< (sizeof(short)*8)) \ 						 | (unsigned short)m )
end_define

begin_define
define|#
directive|define
name|MCSetId
parameter_list|(
name|id
parameter_list|)
value|(unsigned int) ( id>> (sizeof(short) * 8) )
end_define

begin_define
define|#
directive|define
name|MCMsgId
parameter_list|(
name|id
parameter_list|)
value|(unsigned int) ( (id<< (sizeof(short) * 8)) \>> (sizeof(short) * 8) )
end_define

begin_define
define|#
directive|define
name|MCMagicLen
value|8
end_define

begin_define
define|#
directive|define
name|MCMagic
value|"*nazgul*"
end_define

begin_define
define|#
directive|define
name|MCLastMsg
value|0
end_define

begin_define
define|#
directive|define
name|MCLastSet
value|0
end_define

begin_define
define|#
directive|define
name|MCMajorVer
value|1L
end_define

begin_define
define|#
directive|define
name|MCMinorVer
value|0
end_define

begin_comment
comment|/*  * Critical note here.  Sets and Messages *MUST* be stored in ascending  * order.  There are stored that way (by specification) in the original  * data file, however in the process of merging in new stuff you might  * mix that up.  Don't!  The catget stuff does a binary search and will  * totally lose it if these aren't in order (not contiguous mind you, just  * in order.  If this turns out to be a major problem this could be enhanced  * by adding a 'sorted' flag to the db, and sorting msgs and sets at load  * time if things aren't sorted, but I'd like not to have to do that.  */
end_comment

begin_comment
comment|/*  * I have tried here to define data structures which can be used  * while the catalog is on disk, and at runtime.  * This is rather dangerous of course, but I think it can be done without  * overly increasing the memory usage, and it makes loading and storing  * somewhat simpler and less prone to accidents.  I have also tried to  * define on disk data structures which can be updated in place, so that  * with a very large catalog (e.g. all system errors) you don't have to  * load everything in memory in order to add or update one set.  With  * this in mind there are "invalid" flags which allow items to be  * invalidated and thus not loaded at runtime.  Note however that although  * I pay attention to these when I load the DB, I do not currently use  * them in gencat (it just reads everything into memory), so there is  * no guarantee that this will all work.  */
end_comment

begin_comment
comment|/* These should be publicly available */
end_comment

begin_define
define|#
directive|define
name|MCLoadBySet
value|0
end_define

begin_comment
comment|/* Load entire sets as they are used */
end_comment

begin_define
define|#
directive|define
name|MCLoadAll
value|1
end_define

begin_comment
comment|/* Load entire DB on catopen */
end_comment

begin_comment
comment|/*  * MCOffsetT - Union to handle both disk and runtime pointers  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|off_t
name|off
decl_stmt|;
name|char
modifier|*
name|str
decl_stmt|;
name|void
modifier|*
name|ptr
decl_stmt|;
name|struct
name|_MCMsgT
modifier|*
name|msg
decl_stmt|;
name|struct
name|_MCSetT
modifier|*
name|set
decl_stmt|;
block|}
name|MCOffsetT
typedef|;
end_typedef

begin_comment
comment|/*  * MCMsgT - Message structure (disk and runtime)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MCMsgT
block|{
name|long
name|msgId
decl_stmt|;
comment|/* Id of this message */
name|MCOffsetT
name|msg
decl_stmt|;
comment|/* Relative offset on disk or pointer in memory */
name|long
name|invalid
decl_stmt|;
comment|/* Valid on disk, loaded in memory */
block|}
name|MCMsgT
typedef|;
end_typedef

begin_comment
comment|/*  * MCSetT - Set structure (disk and runtime)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_MCSetT
block|{
name|long
name|setId
decl_stmt|;
comment|/* Id of this set */
name|off_t
name|nextSet
decl_stmt|;
comment|/* Offset of next set on disk */
union|union
block|{
name|off_t
name|firstMsg
decl_stmt|;
comment|/* Offset to first Msg (while on disk) */
name|MCMsgT
modifier|*
name|msgs
decl_stmt|;
comment|/* Pointer to array of msgs (in mem, loaded) */
block|}
name|u
union|;
name|MCOffsetT
name|data
decl_stmt|;
comment|/* Offset to data, or pointer to data */
name|long
name|dataLen
decl_stmt|;
comment|/* Length of data area on disk */
name|long
name|numMsgs
decl_stmt|;
comment|/* Number of messages */
name|long
name|invalid
decl_stmt|;
comment|/* Valid on disk, loaded in memory */
block|}
name|MCSetT
typedef|;
end_typedef

begin_comment
comment|/*  * MCCatT - Runtime catalog pointer  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|loadType
decl_stmt|;
comment|/* How to load the messages (see MSLoadType) */
name|FILE
modifier|*
name|fp
decl_stmt|;
comment|/* File descriptor of catalog (if load-on-demand) */
name|long
name|numSets
decl_stmt|;
comment|/* Number of sets */
name|MCSetT
modifier|*
name|sets
decl_stmt|;
comment|/* Pointer to the sets */
name|off_t
name|firstSet
decl_stmt|;
comment|/* Offset of first set on disk */
block|}
name|MCCatT
typedef|;
end_typedef

begin_comment
comment|/*  * MCHeaderT - Disk file header  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|magic
index|[
name|MCMagicLen
index|]
decl_stmt|;
comment|/* Magic cookie "*nazgul*" */
name|long
name|majorVer
decl_stmt|;
comment|/* ++ on incompatible changes */
name|long
name|minorVer
decl_stmt|;
comment|/* ++ on compatible changes */
name|long
name|flags
decl_stmt|;
comment|/* Informational flags */
name|long
name|numSets
decl_stmt|;
comment|/* Number of valid Sets */
name|off_t
name|firstSet
decl_stmt|;
comment|/* Offset of first set on disk */
block|}
name|MCHeaderT
typedef|;
end_typedef

begin_comment
comment|/* Some flags */
end_comment

begin_define
define|#
directive|define
name|MC68KByteOrder
value|0x01
end_define

begin_define
define|#
directive|define
name|MCn86ByteOrder
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MSGCAT_H_ */
end_comment

end_unit

